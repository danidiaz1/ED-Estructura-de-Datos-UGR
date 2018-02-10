#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

int operacion(int *v, int n, int x, int inf, int sup) {
  int med;
  bool enc=false;
  while ((inf<sup) && (!enc)) {
    med = (inf+sup)/2; 
    if (v[med]==x) 
      enc = true;
    else if (v[med] < x) 
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc) 
    return med;
  else 
    return -1;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
	for (int j = 1, tam = 100; j <= 15; j++, tam+=100){
	  // Generación del vector aleatorio
	  int *v=new int[tam];       // Reserva de memoria
	  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
	  for (int i=0; i<tam; i++)  // Recorrer vector
	    v[i] = rand() % tam;
	
	  clock_t tini;    // Anotamos el tiempo de inicio
	  int num_ejecuciones = 500000000;
	  
	  tini=clock();
	
	  // Algoritmo a evaluar
	  for (int i = 0; i < num_ejecuciones; i++)
	  	operacion(v,tam,tam+1,0,tam-1);
	  
	  clock_t tfin;    // Anotamos el tiempo de finalización
	  tfin=clock();
	
	  // Mostramos resultados
	  cout << tam << "\t" << tfin-tini<< endl;
	
	  delete [] v;     // Liberamos memoria dinámica
	}  
}
