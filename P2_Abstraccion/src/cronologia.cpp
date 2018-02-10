#include <iostream>
#include "cronologia.h"
#include <algorithm>

using namespace std;


// Ordenar
void Cronologia::ordenar(){
	sort( c.begin(), c.end() );
}

// Buscar por año
int Cronologia::buscarAnio(const unsigned int fecha){
	vector<FechaHistorica>::const_iterator it;

	int pos = -1;
	bool encontrado = false;

	for (it = c.begin(); it != c.end() && !encontrado; it++){
		
		if ((*it).fecha() == fecha){
    		encontrado = true;
    		pos = it - c.begin();
    	}
	}

    	

    return pos;
}

// Constructor por defecto
Cronologia::Cronologia(){}

// Constructor con parámetros
Cronologia::Cronologia(const vector<FechaHistorica> & f):c(f){
	ordenar();
}

// Constructor de copia
Cronologia::Cronologia(const Cronologia& otra):c(otra.c){}

// Añadir fecha histórica
void Cronologia::aniadirFechaHistorica(FechaHistorica & f){
	int pos = buscarAnio(f.fecha());
    if ( pos == -1){
    	c.push_back(f);
    	ordenar();
    } else 
    	c[pos] = f+c[pos];
}

// Eliminar fecha histórica
bool Cronologia::eliminarFechaHistorica(const unsigned int f){
	int pos = buscarAnio(f);
	bool eliminado = false;
	if (pos != -1){
		c.erase(c.begin()+pos);
		eliminado = true;
	}

	return eliminado;
}

// Obtener eventos por año
FechaHistorica Cronologia::buscarEventos(const unsigned int anio){

	FechaHistorica f;
	int pos = buscarAnio(anio);

    if (pos != -1)
    	f = c[pos];

	return (f);
}

// Obtener eventos por cadena
Cronologia Cronologia::buscarEventos(const string & s){
	Cronologia nuevo;

	vector<FechaHistorica>::const_iterator it;

	for (it = c.begin(); it != c.end(); it++){
		FechaHistorica aux;
		if ((*it).buscarEventos(s,aux))
			nuevo.aniadirFechaHistorica(aux);
	}

	nuevo.ordenar();
	return nuevo;
}

// Obtener eventos por rango de años
Cronologia Cronologia::buscarEventos(const unsigned int i, const unsigned int f){
	Cronologia nuevo;

	vector<FechaHistorica>::const_iterator it;

	for (it = c.begin(); it != c.end(); it++)
		if ((*it).fecha() >= i && (*it).fecha() <= f)
			nuevo.c.push_back(*it);

	return nuevo;
}

// Unión de cronologías
Cronologia Cronologia::operator+(const Cronologia & cr) {
	Cronologia menor;
	Cronologia mayor;

	if (cr.c.size() < c.size()){
		menor = cr;
		mayor = c;
	}
	else{
		menor = c;
		mayor = cr;
	}

	Cronologia nueva = menor;
	vector<FechaHistorica>::iterator it;

	
	for (it = mayor.c.begin(); it != mayor.c.end(); it++){
		int pos = menor.buscarAnio((*it).fecha());

		bool encontrado = pos != -1;
		
		if (!encontrado)
			nueva.aniadirFechaHistorica(*it);
		else
		{
			FechaHistorica f = (*it)+menor.c[pos];
			nueva.aniadirFechaHistorica(f);
		}
	}

	nueva.ordenar();
	return nueva;
}

// Operador de asignación
Cronologia & Cronologia::operator= (const Cronologia & otra){
	c = otra.c;

	return *this;
}

// Operador <<
ostream& operator<< (ostream& os, Cronologia& cr){
	vector<FechaHistorica>::iterator it;

	for (it = cr.c.begin(); it != cr.c.end(); it++)
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