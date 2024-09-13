#include <iostream>
using namespace std;

void ingresarNumArreglo(int, int[]);
void mostrarArreglo(int, int[]);
void interDirDer(int, int[]);

int main() {
	int numerosArreglo, arreglo[100];
	cout << "Ingresa cuantos numeros tendra el arreglo (MAX 100): ";
	cin >> numerosArreglo;
	if ( numerosArreglo > 100 ) {
		cout << "ERROR: SOBREPASO EL LIMITE" << endl;
	} else {
		ingresarNumArreglo(numerosArreglo, arreglo);
		mostrarArreglo(numerosArreglo, arreglo);
		interDirDer(numerosArreglo, arreglo);
		mostrarArreglo(numerosArreglo, arreglo);
	}
}

void ingresarNumArreglo(int numerosArreglo, int arreglo[100]) {
	for ( int i = 0; i < numerosArreglo; i++ ) {
		cout << "Ingresa el valor nro " << i+1 << " :";
		cin >> arreglo[i];
	}
}

void mostrarArreglo(int numerosArreglo, int arreglo[100]) {
	cout << "Arreglo ingresado: " << endl;
	for ( int i = 0; i < numerosArreglo; i++ ) {
		cout << arreglo[i] << "  ";
	}
	cout << endl;
}

void interDirDer(int numerosArreglo, int arreglo[100]) {
	int aux;
	for ( int i = 0; i < numerosArreglo-1; i++ ) {
		for ( int j = 0; j < numerosArreglo-i-1; j++ ) {
			if ( arreglo[j] > arreglo [j+1] ) {
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}
}
