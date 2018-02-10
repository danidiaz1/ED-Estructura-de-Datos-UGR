//#include "cronologia.h"
#include <fstream>
#include <iostream>
#include "fechahistorica.h"
#include "cronologia.h"
#define PROBAR_CRONOLOGIA 1
#define PROBAR_FECHA 0

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
  }

  ifstream f (argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
   
  //Cronologia mi_cronologia;
  //f>>mi_cronologia; //Cargamos en memoria la cronología.
  
  cout << "NOTA: Si se quiere ver la funcionalidad individual de la clase 'FechaHistorica'," <<
  " definir la variable 'PROBAR_FECHA' del preprocesador a '1'. Por defecto, se verá "
  << "La funcionalidad de la clase 'Cronologia'"<< endl << endl << "Pulsa Enter para continuar." <<
  endl << endl;
  
  cin.get();
  #if PROBAR_FECHA == 1
  cout << "/******** Prueba de la clase 'FechaHistorica' **********" << endl;
  
  FechaHistorica mi_fecha, mi_fecha3;
  f >> mi_fecha;
  cout << endl << endl << "Imprimiendo mi fecha: " << endl << mi_fecha << endl << endl;
  cout << "Añade un acontecimiento: ";
  string nuevo = "";
  cin >> nuevo;
  mi_fecha.aniadirAcontecimiento(nuevo);

  cout << endl << endl << "Imprimiendo mi fecha: " << endl << mi_fecha << endl << endl;

  cout << "Elimina un acontecimiento: ";
  string eliminar = "";
  cin >> eliminar;
  mi_fecha.eliminarAcontecimiento(eliminar);

  cout << endl << endl << "Imprimiendo mi fecha: " << endl << mi_fecha << endl << endl;

  unsigned int nuevo_anio = 0;
  cout << "Introduce un nuevo año para la fecha: ";
  cin >> nuevo_anio;

  mi_fecha.fecha() = nuevo_anio;

  cout << endl << endl << "Imprimiendo mi fecha: " << endl << mi_fecha << endl;

  cout << "Creamos otra fecha para probar los operadores. ";
  vector<string> ac;
  ac.push_back("Acontecimiento de prueba 1");
  ac.push_back("Acontecimiento de prueba 2");

  FechaHistorica mi_fecha2(mi_fecha.fecha(), ac);

  cout << endl << endl << "Imprimiendo mi fecha: " << endl << mi_fecha << endl;
  cout << endl << endl << "Imprimiendo mi fecha 2: " << endl << mi_fecha2 << endl << endl;

  FechaHistorica union_fechas = mi_fecha + mi_fecha2;
  cout << "Union de las fechas (operator+): " << endl << union_fechas << endl << endl;

  cout << "Introduce una palabra clave a buscar en la unión de las fechas dadas: ";
  string palabra_clave = "";
  cin >> palabra_clave;
  
  cout << endl << endl;

  if (union_fechas.buscarEventos(palabra_clave, mi_fecha3))
  	cout << "Se encontraron resultados. Nueva fecha: " << endl << mi_fecha3;
  else
  	cout << "No se encontraron resultados.";

  cout << endl << endl;
  #endif

  #if PROBAR_CRONOLOGIA == 1
  
  cout << endl << endl << "/******** Prueba de la clase 'FechaHistorica' **********" << endl;

  Cronologia c1;
  vector<string> acont;
  ifstream f2(argv[1]);
  if (!f2){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  f2 >> c1;
  cout << endl << endl << "Imprimiendo cronologia 1: " << endl << endl << c1 << endl;



  cout << endl << "Introduce un año para obtener los acaecidos en el mismo: ";
  string string_anio;
  cin >> string_anio;
  unsigned int anio = stoi(string_anio);
  FechaHistorica f_obtener = c1.buscarEventos(anio);
  cout << endl << "Resultado: " << endl << endl << f_obtener << endl << endl;



  cout << endl << "Introduce una palabra para obtener la subcronología asociada: ";
  string busqueda;
  cin >> busqueda;
  Cronologia buscada = c1.buscarEventos(busqueda);
  cout << endl << "Resultado: " << endl << endl << buscada << endl << endl;


  cout << endl << "Prueba de la unión de cronologias. Introduce la ruta de otra cronologia: ";
  string nueva_crono;
  cin >> nueva_crono;
  ifstream f3(nueva_crono);
  Cronologia union_crono;
  if (!f3){
    cout<<"No puedo abrir el fichero "<<nueva_crono<<endl;
    return 0;
  } else {
  	Cronologia c2;
    f3 >> c2;
    union_crono = c1 + c2;
    cout << endl << "Resultado: " << endl << endl << union_crono << endl << endl;
  }

  cout << endl << "Introduce un rango de años para obtener la subcronología asociada de " << 
  "la subcronologia union anteriormente obtenida." << endl << "Inicio: ";
  string sinicio,sfin;
  cin >> sinicio;
  cout << endl << "Fin: ";
  cin >> sfin;
  unsigned int inicio, fin;
  inicio = stoi(sinicio);
  fin = stoi(sfin);
  Cronologia buscada2 = union_crono.buscarEventos(inicio,fin);
  cout << endl << "Resultado: " << endl << endl << buscada2 << endl << endl;
  

  #endif
   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés


}
