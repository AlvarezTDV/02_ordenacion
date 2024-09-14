#include <iostream>
using namespace std;

//INICIALIZACION DE LAS FUNCIONES
void ingresarNumArreglo(int, int[]);
void mostrarArreglo(int, int[]);
void interDirDer(int, int[]);

int main() {
	int numerosArreglo, arreglo[100];
	cout << "Ingresa cuantos numeros tendra el arreglo (MAX 100): ";
	cin >> numerosArreglo;
	//CONDICION PARA COMPROBAR SI EL USUARIO NO SOBREPASO EL LIMITE
	if ( numerosArreglo > 100 ) {
		cout << "ERROR: SOBREPASO EL LIMITE" << endl;
	} else {
		ingresarNumArreglo(numerosArreglo, arreglo);
		mostrarArreglo(numerosArreglo, arreglo);
		interDirDer(numerosArreglo, arreglo);
		mostrarArreglo(numerosArreglo, arreglo);
	}
}

//FUNCION PARA INGRESAR DATOS A UN ARREGLO
void ingresarNumArreglo(int numerosArreglo, int arreglo[100]) {
	for ( int i = 0; i < numerosArreglo; i++ ) {
		cout << "Ingresa el valor nro " << i+1 << " :";
		cin >> arreglo[i];
	}
}

//FUNCION PARA MOSTRAR EL ARREGLO
void mostrarArreglo(int numerosArreglo, int arreglo[100]) {
	cout << "Arreglo ingresado: " << endl;
	for ( int i = 0; i < numerosArreglo; i++ ) {
		cout << arreglo[i] << "  ";
	}
	cout << endl;
}

//FUNCION INTERCAMBIO DIRECTO: POR LA DERECHA
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
