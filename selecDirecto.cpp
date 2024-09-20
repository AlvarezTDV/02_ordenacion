#include <iostream>
using namespace std;

void ingresarNumArreglo(int, int[]);
void mostrarArreglo(int, int []);
void seleccionDir(int, int []);

int main() {
	int capacidad, arreglo[100];
	cout << "Ingresa la capacidad del arreglo (max 100): ";
	cin >> capacidad;
	if ( capacidad > 100 ) {
		cout << "ERROR: SOBREPASO EL LIMITE" << endl;
	} else if ( capacidad <= 0) {
		cout << "ERROR: DEBE INGRESAR UN VALOR POSITIVO";
	} else {
		ingresarNumArreglo(capacidad, arreglo);
		cout << "ARREGLO INGRESADO:" << endl;
		mostrarArreglo(capacidad, arreglo);
		seleccionDir(capacidad, arreglo);
		cout << "ARREGLO ORDENADO: " << endl;
		mostrarArreglo(capacidad, arreglo);
	}
	return 0;
}

//FUNCION PARA INGRESAR DATOS A UN ARREGLO
void ingresarNumArreglo(int capacidad, int arreglo[100]) {
	for ( int i = 0; i < capacidad; i++ ) {
		cout << "Ingresa el valor nro " << i+1 << ": ";
		cin >> arreglo[i];
	}
}
//FUNCION PARA MOSTRAR EL ARREGLO
void mostrarArreglo(int capacidad, int arreglo[100]) {
	for ( int i = 0; i < capacidad; i++ ) {
		cout << arreglo[i] << "  ";
	}
	cout << endl;
}

//FUNCION DE SELECCION DIRECTA
void seleccionDir(int capacidad, int arreglo[100]) {
	int menor, k;
	for ( int i = 0; i < capacidad; i++ ) {
		menor = arreglo[i];
		k = i;
		for ( int j = i + 1; j < capacidad; j++ ) {
			if ( arreglo[j] < menor ) {
				menor = arreglo[j];
				k = j;
			}
		}
		arreglo[k] = arreglo[i];
		arreglo[i] = menor;
	}
}
