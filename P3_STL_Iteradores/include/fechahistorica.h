/**
  * @file fechahistorica.h
  * @brief Fichero cabecera del TDA Fecha Histórica
  *
  */

#ifndef __FECHAHISTORICA
#define __FECHAHISTORICA

#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

/**
  *  @brief T.D.A. Fecha Histórica
  *
  * Una instancia @e c del tipo de datos abstracto @c Fecha Histórica se
  * compone de una fecha y uno o más eventos sucedidos en dicha
  * fecha. La fecha representará únicamente el año en el que tuvieron lugar los
  * acontecimientos en forma de número natural, y cada uno de los acontecimientos
  * podrá contener más de una palabra.
  *
  * @author Daniel Díaz Pareja
  * @date Octubre 2017
  */

class FechaHistorica {

 private:
/**
  * @page repConjunto Rep del TDA Fecha Histórica
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.fecha >= 0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Fecha Histórica representa al valor
  *
  * (rep.fecha, rep.acontecimientos)
  *
  */

  pair<unsigned int, set<string>> m_pair;
  

 public:

/**
* @brief Constructor por defecto. Crea la FechaHistorica con fecha = 0 y 
*        sin acontecimientos.
*/
  FechaHistorica();

/**
* @brief Constructor de la clase.
* @param fecha Fecha en que se producieron los acontecimientos
* @param acontecimientos Vector de acontecimientos (strings) que se produjeron 
*        en la fecha.
* @return Objeto de tipo FechaHistorica con fecha y acontecimientos introducidos
* @pre fecha >= 0
*/
  FechaHistorica(const unsigned int & fecha, const set<string> & acontecimientos);

/**
  * @brief Constructor de copias de la clase
  * @param otra objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de otra
  */
  FechaHistorica(const FechaHistorica& otra);

/**
* @brief Obtiene la fecha (versión no constante, es decir, para escritura)
* @return Devuelve un entero positivo con la fecha.
*/
  unsigned int & fecha();

/**
* @brief Obtiene la fecha (versión constante, es decir, para lectura)
* @return Devuelve un entero positivo con la fecha.
*/
  const unsigned int & fecha() const;

/**
* @brief Obtiene los acontecimientos (versión no constante, es decir, para escritura).
* @return Vector de Strings con los acontecimientos.
*/
  set<string> & acontecimientos();

/**
* @brief Obtiene los acontecimientos (versión constante, es decir, para lectura).
* @return Vector de Strings con los acontecimientos.
*/
  const set<string> & acontecimientos() const;

/**
* @brief Obtiene el número de acontecimientos de una FechaHistorica
* @return número de acontecimientos.
*/
  const unsigned int numAcontecimientos() const;

/**
* @brief Imprime la fecha histórica en cout.
* @post Se imprime en \a cout lacadena año \\n\\t Acontecimiento1 \\n\\t Acontecimiento2...
*/
  void print();

/**
* @brief Añade un nuevo acontecimiento a la fecha histórica
* @param ac Acontecimiento a añadir
*/
  void aniadirAcontecimiento(const string & ac);

/**
* @brief Elimina un acontecimiento
* @param ac String con el contecimiento a eliminar
* @return true si se ha eliminado, false si no se ha encontrado
*/
  bool eliminarAcontecimiento(const string & ac);

/**
  * @brief busca eventos dada una palabra clave
  * @param s string con la palabra a buscar
  * @param nuevo es el Evento_Historico donde se van a introducir los resultados
  * @return Devuelve true o false indicando si ha encontrado elementos o no
  */
  bool buscarEventos(string s, FechaHistorica &nuevo) const;

/**
  * @brief Salida de una FechaHistorica a ostream
  * @param os stream de salida
  * @param f Racional a escribir
  * @post Se obtiene en \a os la cadena año \\n\\t Acontecimiento1 \\n\\t Acontecimiento2... 
  * con \e f el valor de la fecha y AcontecimientoN el texto con cada acontecimiento.
  */
  friend ostream& operator<< (ostream& os, FechaHistorica& f);

/**
  * @brief Entrada de una FechaHistorica desde istream
  * @param is stream de entrada
  * @param f FechaHistorica que recibe el valor
  * @retval La FechaHistorica leída en f
  * @pre La entrada tiene el formato año#Acontecimiento1#Acontecimiento2#... con \e año
  * el valor de la fecha y AcontecimientoN el texto de cada acontecimiento. Todo en una
  * cadena de texto.
  */
  friend istream& operator>> (istream& is, FechaHistorica& f);

/**
  * @brief Operador de comparación menor
  * @param der Fecha histórica correspondiente a la parte derecha de la expresión  
  * @return true si izq.fecha < der.fecha, false en caso contrario
  */

  bool operator < (const FechaHistorica & der);

  /**
  * @brief Operador de comparación mayor
  * @param der Fecha histórica correspondiente a la parte derecha de la expresión  
  * @return true si izq.fecha > der.fecha, false en caso contrario
  */

  bool operator > (const FechaHistorica & der);

  /**
  * @brief Operador de comparación menor o igual
  * @param der Fecha histórica correspondiente a la parte derecha de la expresión  
  * @return true si izq.fecha <= der.fecha, false en caso contrario
  */

  bool operator <= (const FechaHistorica & der);

  /**
  * @brief Operador de comparación mayor o igual
  * @param der Fecha histórica correspondiente a la parte derecha de la expresión  
  * @return true si izq.fecha >= der.fecha, false en caso contrario
  */

  bool operator >= (const FechaHistorica & der);

  /**
  * @brief Operador de comparación
  * @param der Fecha histórica correspondiente a la parte derecha de la expresión
  * @return true si izq.fecha == der.fecha, false en caso contrario
  */
  bool operator == (const FechaHistorica & der);

  /**
  * @brief Compara el año de la fecha implícita con la pasada por parámetro.
  * @param otra Fecha a comparar.
  * @return true si los años son iguales, false si no.
  */
  bool mismoAnio (const FechaHistorica & otra);

  /**
  * @brief Operador suma. Une los eventos de dos fechas históricas con el mismo año.
  * @param otra Fecha a sumar.
  * @pre otra.fecha == (*this).fecha
  * @return Unión de las fechas históricas.
  */
  FechaHistorica operator+ (const FechaHistorica & otra);

  /**
  * @brief Operador de asignación.
  * @param otra Fecha histórica a asignar al objeto implícito.
  * @return Objeto implícito.
  */
  FechaHistorica & operator= (const FechaHistorica & otra);

  /**
  * @brief Clase para iterar sobre los eventos históricos
  */
  class iterator{
    private:
      set<string>::iterator it;

    public:

      iterator & operator++(){
        ++it;
        return *this;
      }

      iterator & operator--(){
        --it;
        return *this;
      }

      const string & operator*(){
        return *it;
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
      
      friend class FechaHistorica;
  };

  /**
  * @brief busca un evento exacto dado
  * @param s string con el evento a buscar
  * @param it_out Devuelve un iterador a la posición donde está el evento.
      Si no está, devuelve end(). 
  * @return Devuelve true o false indicando si está o no está
  */
  bool buscarEventos(string s, iterator &it_out) const;

  /**
  * @brief Inicializa un iterator al comienzo de los eventos históricos
  */
  iterator begin(){
    iterator i;
    i.it=m_pair.second.begin();
    return i;
  }

  /**
  * @brief Inicializa un iterator al final de los eventos históricos
  */
  iterator end(){
    iterator i;
    i.it=m_pair.second.end();
    return i;
  }

  /**
  * @brief Clase const_iterator para iterar sobre los eventos históricos
  */
  class const_iterator{
    private:
      set<string>::iterator it;

    public:

      const_iterator & operator++(){
        ++it;
        return *this;
      }

      const_iterator & operator--(){
        --it;
        return *this;
      }

      const string & operator*() const{
        return *it;
      }

      bool operator ==(const const_iterator &i) const {
        return i.it==it;
      }    

      bool operator !=(const const_iterator &i) const {
        return i.it!=it;
      }

      const_iterator & operator=(const const_iterator &i){
        it = i.it;

        return *this;
      }
      
      friend class FechaHistorica;
  };

  /**
  * @brief Inicializa un const_iterator al comienzo de los eventos históricos
  */
  const_iterator begin() const{
    const_iterator i;
    i.it=m_pair.second.begin();
    return i;
  }

  /**
  * @brief Inicializa un const_iterator al final de los eventos históricos
  */
  const_iterator end() const{
    const_iterator i;
    i.it=m_pair.second.end();
    return i;
  }
};

#endif