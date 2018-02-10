#include <fstream>
#include <iostream>
#include "fechahistorica.h"
#include "cronologia.h"

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=3){
      cout<<"Dime dos nombres de fichero para unir dos cronologías"<<endl;
      return 0;
  }

  ifstream f1 (argv[1]);
  ifstream f2 (argv[2]);
  if (!f1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  } else if (!f2) {
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
  }
  
  Cronologia c1, c2, union_crono;
  f1 >> c1;
  f2 >> c2;

  union_crono = c1+c2;

  cout << endl << "Unión de las cronologías: " << union_crono << endl;
  
}
