#include <iostream>
#include <ctime>

using namespace std;

// Creamos un vector totalmente desordenado. P ej: 9, 8, 7, 6, ... 1, 0
void crear_vector(int *v, int n_datos){
  	for (int i=0; i<n_datos; i++)
  		v[i]=i;
}

/*for (int i=0, j=n_datos-1; i<n_datos; i++,j--)
  	 v[i]=j;*/
// _Ordenación Burbuja. O(n²) peor caso
void ordenar(int *v, int n) {
	bool cambio=true;
	for (int i=0; i<n-1 && cambio; i++) {
		cambio=false;
		for (int j=0; j<n-i-1; j++)
			if (v[j]>v[j+1]) {
				cambio=true;
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
	}
}

int main(void){
  clock_t ti, tf;
  
  for(int n_datos=100; n_datos<30000000; n_datos+= 500000){
  	
  	 int *v=new int[n_datos];       // Reserva de memoria
	 for (int i=0; i<n_datos; i++)
  		v[i]=i;
    ti = clock();
    ordenar(v,n_datos);
    tf = clock();
    cout << n_datos << "\t" << tf - ti << endl;
    
    delete [] v;     // Liberamos memoria dinámica
  }
}
