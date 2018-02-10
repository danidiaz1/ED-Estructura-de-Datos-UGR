#include <iostream>
#include "fechahistorica.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

// Constructor por defecto
FechaHistorica::FechaHistorica() : m_fecha{0}{}

// Constructor con parámetros
FechaHistorica::FechaHistorica(const unsigned int & fecha, const vector<string> & acontecimientos)
 : m_fecha{fecha}, m_acontecimientos{acontecimientos} {}

// Constructor de copias
FechaHistorica::FechaHistorica(const FechaHistorica &otra){
	m_fecha = otra.m_fecha;
	m_acontecimientos = otra.m_acontecimientos;
}

// Getter de la fecha (escritura)
unsigned int & FechaHistorica::fecha(){
	return m_fecha;
}

// Getter de la fecha (lectura)
const unsigned int & FechaHistorica::fecha() const {
	return m_fecha;
}

// Getter de los acontecimientos
vector<string> & FechaHistorica::acontecimientos() {
	return m_acontecimientos;
}

const vector<string> & FechaHistorica::acontecimientos() const {
	return m_acontecimientos;
}

// Imprime la fecha histórica en cout
void FechaHistorica::print(){
	cout << m_fecha;

	for(vector<string>::const_iterator it = m_acontecimientos.begin(); it != m_acontecimientos.end(); it++)
		cout << endl << "\t" << *it;

	cout << endl;
}

// Añade un acontecimiento
void FechaHistorica::aniadirAcontecimiento(const string & ac){
	m_acontecimientos.push_back(ac);
}

// Elimina un acontecimiento
void FechaHistorica::eliminarAcontecimiento(const string & ac){
	m_acontecimientos.erase(std::remove
		(m_acontecimientos.begin(), m_acontecimientos.end(), ac), 
		m_acontecimientos.end()
	);
}

// Buscador de eventos
bool FechaHistorica::buscarEventos(string s, FechaHistorica &nuevo) const{
	bool encontrado = false;
	vector<string>::const_iterator it;

	for(it = m_acontecimientos.begin(); it != m_acontecimientos.end(); it++){
		if ((*it).find(s) < 1000000){
			nuevo.aniadirAcontecimiento(*it);
			encontrado = true;
		}
	}

	if (encontrado)
		nuevo.m_fecha = m_fecha;

	return encontrado;
}

// Buscador de eventos 2
bool FechaHistorica::buscarEventos(string s) const{
	bool encontrado = false;
	vector<string>::const_iterator it;

	for(it = m_acontecimientos.begin(); it != m_acontecimientos.end() && encontrado; it++)
		if ((*it).find(s) < 1000000)
			encontrado = true;

	return encontrado;
}

// Operador <
bool FechaHistorica::operator< (const FechaHistorica & der){
  	return (m_fecha < der.m_fecha);
}

// Operador >
bool FechaHistorica::operator> (const FechaHistorica & der){
	return (m_fecha > der.m_fecha);
}

// Operador <=
bool FechaHistorica::operator<= (const FechaHistorica & der){
  	return (m_fecha <= der.m_fecha);
}

// Operador >=
bool FechaHistorica::operator>= (const FechaHistorica & der){
  	return (m_fecha >= der.m_fecha);
}

// Operador ==
bool FechaHistorica::operator== (const FechaHistorica & der){
  	return (m_fecha == der.m_fecha && m_acontecimientos == der.m_acontecimientos);
}

// Mismo año que otra FH
bool FechaHistorica::mismoAnio (const FechaHistorica & otra){
	return (m_fecha == otra.m_fecha);
}

// Operador de asignación (=)
FechaHistorica & FechaHistorica::operator= (const FechaHistorica & otra){
	m_fecha = otra.m_fecha;
	m_acontecimientos = otra.m_acontecimientos;

	return *this;
}

// Operador +
FechaHistorica FechaHistorica::operator+ (const FechaHistorica & otra){
	assert(otra.m_fecha == m_fecha);
	vector<string>::const_iterator it;
	unsigned int f = m_fecha;
	vector<string> a; // nuevo vector para la suma

	// Comparamos los tamaños de los vectores para crear una copia del más grande y así iterar por el más
	// pequeño.
	if (m_acontecimientos.size() > otra.m_acontecimientos.size() ){
		a = m_acontecimientos;

		for (it = otra.m_acontecimientos.begin(); it != otra.m_acontecimientos.end(); it++)
			if (!buscarEventos(*it)) // Si el acontecimiento no está en "a"
				a.push_back(*it); // lo insertamos
	}
	else{
		a = otra.m_acontecimientos;

		for (it = m_acontecimientos.begin(); it != m_acontecimientos.end(); it++)
			if (!otra.buscarEventos(*it)) // Si el acontecimiento no está en "a"
				a.push_back(*it); // lo insertamos		
	}

	return FechaHistorica(f,a);
}

// Operador <<
ostream& operator<< (ostream& os, FechaHistorica& f){
	vector<string>::const_iterator it;

	os << f.m_fecha;

	for(it = f.m_acontecimientos.begin(); it != f.m_acontecimientos.end(); it++)
		os << endl << "\t" << *it;

	return os ;
}

// Operador >>
istream& operator>> (istream& is, FechaHistorica& f){
	char separador = '#';
	unsigned int fec;
	string linea, token;
	vector<string> ac;

	getline(is,linea);
	stringstream linestream(linea);

	// Obtención de la fecha
	getline(linestream, token, separador);
	if (token != "")
		fec = stoi(token);

	// Obtención de los acontecimientos
	while (getline(linestream, token, separador))
		ac.push_back(token);

	f= FechaHistorica(fec,ac);

	return is;
}