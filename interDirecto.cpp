#include <iostream>
using namespace std;

void ingresarNumArreglo(int, int[]);
void mostrarArreglo(int, int[]);

int main() {
	int numerosArreglo, arreglo[100];
	cout << "Ingresa cuantos numeros tendra el arreglo (MAX 100): ";
	cin >> numerosArreglo;
	ingresarNumArreglo(numerosArreglo, arreglo);
	mostrarArreglo(numerosArreglo, arreglo);
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
}