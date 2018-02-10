#include <fstream>
#include <iostream>
#include <iomanip>
#include "fechahistorica.h"
#include "cronologia.h"

using namespace std;

int main(int argc, char * argv[]){

  if (argc < 2){
      cout<<"Dime un nombre de fichero con la cronología " << endl;
      return 0;
  }

  ifstream f1 (argv[1]);

  if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  Cronologia c1;
  f1 >> c1;

  cout << "Estadísticas sobre eventos para la cronología " << argv[1] << endl << endl;
  cout << "Total de años: " << c1.totalAnios() << endl;
  cout << "Total de acontecimientos: " << c1.totalAcontecimientos() << endl;
  cout << "Máximo de acontecimientos en un año: " << c1.maxAcontecimientos() << endl;
  cout << "Promedio de acontecimientos por año: " << std::fixed << std::setprecision(3) << 
  c1.promedioAcontecimientos() << endl;

}
