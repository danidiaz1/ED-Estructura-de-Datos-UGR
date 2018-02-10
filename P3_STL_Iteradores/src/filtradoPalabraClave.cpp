#include <fstream>
#include <iostream>
#include "fechahistorica.h"
#include "cronologia.h"

using namespace std;

int main(int argc, char * argv[]){

  if (argc<2){
      cout<<"Dime un nombre de fichero con la cronología." << 
      " También puedes poner la palabra a buscar y el fichero " << 
      "donde quieres que se guarden los resultados."<<endl;
      return 0;
  }

  ifstream f1 (argv[1]);

  if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  string palabra;

  if (argc >= 3)
    palabra = argv[2];
  else
  {
    cout << "Introduce una palabra a buscar: "<<endl;
    cin>>palabra;
  }
  
  Cronologia c1, busqueda;
  f1 >> c1;

  busqueda = c1.buscarEventos(palabra);

  if (argc >= 4){
    ofstream fichero;
    fichero.open(argv[3]);
    fichero << busqueda;
    fichero.close();
  }
  else
    cout << endl << busqueda << endl;
}
