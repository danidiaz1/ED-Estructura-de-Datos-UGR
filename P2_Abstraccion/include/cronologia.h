/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include <vector>
#include "fechahistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un conjunto
  * de fechas históricas ordenadas por año.
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Daniel Díaz Pareja
  * @date Octubre 2017
  */

class Cronologia {

 private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * Si consideramos una Cronologia como un conjunto de fechas históricas
  * c={ f1, f2, f3...} el invariante es 
  * \e f1.fecha < fn+1.fecha y no existen fechas históricas tal que \e fi == fj
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa al valor
  *
  * rep.c={f1, f2, f3,...}
  * 
  */

  vector<FechaHistorica> c;


  void ordenar(); //Ordena el vector c de fechas históricas de menor a mayor.
  int buscarAnio(const unsigned int fecha); // Busca en el vector c si existe alguna fecha con el año fecha
                                        // Devuelve la posición en el vector (-1 si no se encuentra)

 public:
// Se omite el constructor por defecto, ya que el dado por el compilador crearía
// el vector c con 0 elementos, que es lo que se pretende

/**
  * @brief Constructor por defecto.
  * @return Objeto Cronología sin fechas históricas.
  */
  Cronologia();

/**
  * @brief Constructor con parámetros.
  * @param f Vector de fechas históricas.
  * @return Objeto Cronología con fechas históricas.
  */
  Cronologia(const vector<FechaHistorica> & f);

/**
  * @brief Constructor de copias de la clase
  * @param otra objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de c
  */
  Cronologia(const Cronologia& otra);

/**
 * @brief Añade una fecha histórica a la cronología. Si ya existía el año de la 
 * fecha histórica, realiza la union de las fechas.
 * @param f Fecha histórica a añadir
 */
  void aniadirFechaHistorica(FechaHistorica & f);

/**
 * @brief Elimina una fecha histórica de la cronología.
 * @param f Año de la fecha histórica a eliminar.
 * @return true si se ha eliminado, false si no se ha encontrado
 */
  bool eliminarFechaHistorica(const unsigned int f);

/**
 * @brief Obtiene los eventos acaecidos en un año.
 * @param anio Año del que obtener los eventos.
 * @pre anio >= 0
 * @return Objeto FechaHistorica cuya fecha es "anio" y con los acontecimientos
 * sucedidos en el mismo. Si no se encuentra, se devuelve la fecha histórica vacía.
 */
  FechaHistorica buscarEventos(const unsigned int anio);

/**
  * @brief buscador de eventos dado una palabra clave
  * @param s vector de string con la palabra a buscar
  * @return Devuelve una nueva Cronología
  */
  Cronologia buscarEventos(const string & s);

/**
 * @brief Obtiene los eventos en un rango de años.
 * @param i Año inicial.
 * @param f Año final.
 * @pre anio_inicial >= 0
 * @return Devuelve una nueva Cronología.
 */
  Cronologia buscarEventos(const unsigned int i, const unsigned int f);

/**
 * @brief Operador suma. Realiza la unión de dos cronologías
 * @param cr Cronología a unir.
 * @return Nueva cronologia con la unión
 */
  Cronologia operator+(const Cronologia & cr);

  /**
  * @brief Salida de una Cronologia a ostream
  * @param os stream de salida
  * @param cr Cronologia a escribir
  */
  friend ostream& operator<< (ostream& os, Cronologia& cr);

/**
  * @brief Entrada de una Cronologia desde istream
  * @param is stream de entrada
  * @param cr Cronologia que recibe el valor
  * @retval La Cronologia leída en c
  * @pre La entrada tiene el formato año#Acontecimiento1#Acontecimiento2\\n
  año#Acontecimiento1#Acontecimiento2\\naño#Acontecimiento1#Acontecimiento2...
  */
  friend istream& operator>> (istream& is, Cronologia& cr);

/**
  * @brief Operador de asignación.
  * @param otra Cronologia a asignar al objeto implícito.
  * @return Objeto implícito.
  */
  Cronologia & operator= (const Cronologia & otra);
};

#endif
