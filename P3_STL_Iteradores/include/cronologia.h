/**
  * @file cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include <map>
#include "fechahistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un conjunto
  * de fechas históricas ordenadas por año.
  *
  * Ejemplos de su uso:
  * @include union_cronologia.cpp
  * @include filtradoPalabraClave.cpp
  * @include filtradoIntervalo.cpp
  * @include estadisticaEventos.cpp
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

  map<unsigned int, FechaHistorica> c;

 public:

/**
  * @brief Constructor por defecto.
  * @return Objeto Cronología sin fechas históricas.
  */
  Cronologia();

/**
  * @brief Constructor de copias de la clase
  * @param otra objeto de la clase que se quiere copiar
  * @return Cronología con los datos de otra
  */
  Cronologia(const Cronologia & otra);

/**
 * @brief Añade una fecha histórica a la cronología. Si ya existía el año de la 
 * fecha histórica, realiza la union de las fechas.
 * @param f Fecha histórica a añadir
 */
  void aniadirFechaHistorica(FechaHistorica & f);

/**
 * @brief Elimina una fecha histórica de la cronología.
 * @param f Año de la fecha histórica a eliminar.
 * @return número de elementos borrados
 */
  unsigned int eliminarFechaHistorica(const unsigned int f);

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
  * @brief Cuenta el número total de años para los que se especifican FechasHistoricas
  * en la Cronología
  * @return número de años para los que hay eventos históricos
  */
  const unsigned int totalAnios() const;

/**
  * @brief Cuenta el número total de acontecimientos de la Cronología
  * @return número total de acontecimientos
  */
  const unsigned int totalAcontecimientos() const;

/**
  * @brief Calcula el número máximo de acontecimientos de una FechaHistórica
  * en la Cronología
  * @return número máximo de acontecimientos en la cronología
  */
  const unsigned int maxAcontecimientos() const;

/**
  * @brief Calcula el promedio de acontecimientos por año en la Cronología
  * @return promedio de acontecimientos
  */
  const float promedioAcontecimientos() const;

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

  /**
  * @brief Clase para iterar sobre la cronologia
  */
  class iterator{
    private:
      map<unsigned int, FechaHistorica>::iterator it;

    public:
      iterator & operator++(){
        ++it;
        return *this;
      }

      iterator & operator--(){
        --it;
        return *this;
      }

      FechaHistorica & operator*(){
        return (*it).second;
      }

      bool operator ==(const iterator &i){
        return i.it==it;
      }    

      bool operator !=(const iterator &i){
        return i.it!=it;
      }

      iterator & operator=(const iterator &i){
        it = i.it;

        return *this;
      }
      
      friend class Cronologia;
  };

  /**
  * @brief Inicializa un iterator al comienzo de la cronología
  */
  iterator begin(){
    iterator i;
    i.it=c.begin();
    return i;
  }

  /**
  * @brief Inicializa un iterator al final de la cronología
  */
  iterator end(){
    iterator i;
    i.it=c.end();
    return i;
  }

  /**
  * @brief Clase para iterar sobre la cronologia (modo const)
  */
  class const_iterator{
    private:
      map<unsigned int, FechaHistorica>::const_iterator it;

    public:
      const_iterator & operator++(){
        ++it;
        return *this;
      }

      const_iterator & operator--(){
        --it;
        return *this;
      }

      const FechaHistorica & operator*() const{
        return (*it).second;
      }

      bool operator ==(const const_iterator &i) const{
        return i.it==it;
      }    

      bool operator !=(const const_iterator &i) const{
        return i.it!=it;
      }

      const_iterator & operator=(const const_iterator &i){
        it = i.it;

        return *this;
      }
      
      friend class Cronologia;
  };

  /**
  * @brief Inicializa un const_iterator al comienzo de la cronología
  */
  const_iterator begin() const{
    const_iterator i;
    i.it=c.begin();
    return i;
  }

  /**
  * @brief Inicializa un const_iterator al final de la cronología
  */
  const_iterator end() const{
    const_iterator i;
    i.it=c.end();
    return i;
  }
};

#endif
