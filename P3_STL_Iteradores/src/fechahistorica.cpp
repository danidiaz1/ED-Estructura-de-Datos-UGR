#include <iostream>
#include "fechahistorica.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;
#define fec m_pair.first
#define acs m_pair.second

// Constructor por defecto
FechaHistorica::FechaHistorica() {fec = 0;}

// Constructor con parámetros
FechaHistorica::FechaHistorica(const unsigned int & fecha, const set<string> & acontecimientos){
	fec = fecha; 
	acs = acontecimientos;
}

// Constructor de copias
FechaHistorica::FechaHistorica(const FechaHistorica &otra){
	m_pair = otra.m_pair;
}

// Getter de la fecha (escritura)
unsigned int & FechaHistorica::fecha(){
	return fec;
}

// Getter de la fecha (lectura)
const unsigned int & FechaHistorica::fecha() const {
	return fec;
}

// Getter de los acontecimientos
set<string> & FechaHistorica::acontecimientos() {
	return acs;
}

const set<string> & FechaHistorica::acontecimientos() const {
	return acs;
}

// num acontecimientos
const unsigned int FechaHistorica::numAcontecimientos() const {
	return acs.size();
}

// Imprime la fecha histórica en cout
void FechaHistorica::print(){
	cout << fec;

	for(set<string>::const_iterator it = acs.begin(); it != acs.end(); it++)
		cout << endl << "\t" << *it;

	cout << endl;
}

// Añade un acontecimiento
void FechaHistorica::aniadirAcontecimiento(const string & ac){
	acs.insert(ac);
}

// Elimina un acontecimiento
bool FechaHistorica::eliminarAcontecimiento(const string & ac){
	set<string>::iterator buscado = acs.find(ac);
	bool encontrado = false;

	if (buscado != acs.end()){
		acs.erase(buscado);
		encontrado = true;
	}

	return encontrado;
}

// Buscador de eventos
bool FechaHistorica::buscarEventos(string s, FechaHistorica &nuevo) const{
	bool encontrado = false;
	set<string>::const_iterator it;

	for(it = acs.begin(); it != acs.end(); it++){
		if ((*it).find(s) < 1000000){
			nuevo.aniadirAcontecimiento(*it);
			encontrado = true;
		}
	}

	if (encontrado)
		nuevo.fec = fec;

	return encontrado;
}

// Buscador de eventos "exacto"
bool FechaHistorica::buscarEventos(string s, iterator &it_out) const{
	set<string>::iterator buscado = acs.find(s);

	iterator i;
	i.it = buscado;
	it_out.it = i.it;

	if (buscado == acs.end())
		return false;
	else
		return true;
}

// Operador <
bool FechaHistorica::operator< (const FechaHistorica & der){
  	return (fec < der.fec);
}

// Operador >
bool FechaHistorica::operator> (const FechaHistorica & der){
	return (fec > der.fec);
}

// Operador <=
bool FechaHistorica::operator<= (const FechaHistorica & der){
  	return (fec <= der.fec);
}

// Operador >=
bool FechaHistorica::operator>= (const FechaHistorica & der){
  	return (fec >= der.fec);
}

// Operador ==
bool FechaHistorica::operator== (const FechaHistorica & der){
  	return (fec == der.fec && acs == der.acs);
}

// Mismo año que otra FH
bool FechaHistorica::mismoAnio (const FechaHistorica & otra){
	return (fec == otra.fec);
}

// Operador de asignación (=)
FechaHistorica & FechaHistorica::operator= (const FechaHistorica & otra){
	m_pair = otra.m_pair;

	return *this;
}

// Operador +
FechaHistorica FechaHistorica::operator+ (const FechaHistorica & otra){
	assert(otra.fec == fec);
	set<string>::const_iterator it;
	unsigned int f = fec;
	set<string> a; // nuevo set para la suma

	// Comparamos los tamaños de los set para crear una copia del más grande y así iterar por el más
	// pequeño, ya que la iterar es más costoso.
	if (acs.size() > otra.acs.size() ){
		a = acs;

		for (it = otra.acs.begin(); it != otra.acs.end(); it++)
			a.insert(*it);
	}
	else{
		a = otra.acs;

		for (it = acs.begin(); it != acs.end(); it++)
			a.insert(*it);
	}

	return FechaHistorica(f,a);
}

// Operador <<
ostream& operator<< (ostream& os, FechaHistorica& f){
	FechaHistorica::iterator it;

	os << f.fec;

	for(it = f.begin(); it != f.end(); ++it)
		os << endl << "\t" << *it;

	return os ;
}

// Operador >>
istream& operator>> (istream& is, FechaHistorica& f){
	char separador = '#';
	unsigned int fecha;
	string linea, token;
	set<string> ac;

	getline(is,linea);
	stringstream linestream(linea);

	// Obtención de la fecha
	getline(linestream, token, separador);
	
	if (token != "")
		fecha = stoi(token);

	// Obtención de los acontecimientos
	while (getline(linestream, token, separador))
		ac.insert(token);

	f= FechaHistorica(fecha,ac);

	return is;
}