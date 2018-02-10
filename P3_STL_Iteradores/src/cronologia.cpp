#include <iostream>
#include "cronologia.h"
#include <algorithm>
#include <utility>

using namespace std;

// Constructor por defecto
Cronologia::Cronologia(){}

// Constructor de copia
Cronologia::Cronologia(const Cronologia& otra):c(otra.c){}

// Añadir fecha histórica
void Cronologia::aniadirFechaHistorica(FechaHistorica & f){

	unsigned int fecha = f.fecha();
	// Si no se encuentra la fecha, la insertamos
	if ( c.find(fecha) == c.end() )
  		c.insert( pair<unsigned int, FechaHistorica>(fecha,f));
	else // Si se encuentra, la sustituimos por la unión
		c[fecha] = c[fecha]+f;
}

// Eliminar fecha histórica
unsigned int Cronologia::eliminarFechaHistorica(const unsigned int f){
	return c.erase(f); 
}

// Obtener eventos por año
FechaHistorica Cronologia::buscarEventos(const unsigned int anio){

	map<unsigned int, FechaHistorica>::iterator it = c.find(anio);
	
	if (it != c.end())
		return (*it).second;
	else
		return FechaHistorica();
}

// Obtener eventos por cadena
Cronologia Cronologia::buscarEventos(const string & s){
	Cronologia nuevo;

	map<unsigned int, FechaHistorica>::const_iterator it;

	for (it = c.begin(); it != c.end(); it++){
		FechaHistorica aux;
		if ((*it).second.buscarEventos(s,aux))
			nuevo.aniadirFechaHistorica(aux);
	}

	return nuevo;
}

// Obtener eventos por rango de años
Cronologia Cronologia::buscarEventos(const unsigned int i, const unsigned int f){
	Cronologia nuevo;

	map<unsigned int, FechaHistorica>::const_iterator it;

	for (it = c.begin(); it != c.end(); it++)
		if ((*it).first >= i && (*it).first <= f)
			nuevo.c.insert(*it);

	return nuevo;
}

// Unión de cronologías
Cronologia Cronologia::operator+(const Cronologia & cr) {
	Cronologia menor;
	Cronologia mayor;

	if (cr.c.size() < c.size()){
		menor = cr;
		mayor = *this;
	}
	else{
		menor = *this;
		mayor = cr;
	}

	Cronologia nueva = menor;
	map<unsigned int, FechaHistorica>::iterator it;

	for (it = mayor.c.begin(); it != mayor.c.end(); it++)
		nueva.aniadirFechaHistorica((*it).second);
	
	return nueva;
}

// contar años
const unsigned int Cronologia::totalAnios() const{
	return c.size();
}

// Contar acontecimientos
const unsigned int Cronologia::totalAcontecimientos() const {
	map<unsigned int, FechaHistorica>::const_iterator it;
	unsigned int total = 0;

	for (it = c.begin(); it != c.end(); it++)
		total += (*it).second.numAcontecimientos();

	return total;
}

// Máximo de acontecimientos
const unsigned int Cronologia::maxAcontecimientos() const {
	map<unsigned int, FechaHistorica>::const_iterator it;
	unsigned int max = 0;

	for (it = c.begin(); it != c.end(); it++)
		if ((*it).second.numAcontecimientos() > max)
			max = (*it).second.numAcontecimientos();

	return max;
}

// Promedio
const float Cronologia::promedioAcontecimientos() const {
	return totalAcontecimientos()/(float)totalAnios();
}


// Operador de asignación
Cronologia & Cronologia::operator= (const Cronologia & otra){
	c = otra.c;

	return *this;
}

// Operador <<
ostream& operator<< (ostream& os, Cronologia& cr){
	Cronologia::iterator it;

	for (it = cr.begin(); it != cr.end(); ++it)
		os << *it << endl;
	
	return os;     
}

// Operador >>
istream& operator>> (istream& is, Cronologia& cr){
	FechaHistorica f;

	while(is >> f)
		cr.aniadirFechaHistorica(f);
	
	return is;
}