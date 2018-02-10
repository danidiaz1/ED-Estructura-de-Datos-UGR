#include <fstream>
#include <iostream>
#include "fechahistorica.h"
#include "cronologia.h"

using namespace std;

int main(int argc, char * argv[]){

  if (argc<4){
      cout<<"Dime un nombre de fichero con la cronología, " <<
      "el año de inicio y el año de fin del intervalo." <<
      " También puedes poner el fichero donde quieres " <<
      "que se guarden los resultados." << endl;
      return 0;
  }

  ifstream f1 (argv[1]);

  if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  int inicio, fin;
  Cronologia c1, intervalo;
  f1 >> c1;

  inicio = atoi(argv[2]);
  fin = atoi(argv[3]);


  intervalo = c1.buscarEventos(inicio,fin);

  if (argc >= 5){
    ofstream fichero;
    fichero.open(argv[4]);
    fichero << intervalo;
    fichero.close();
  }
  else
    cout << endl << intervalo << endl;
}
