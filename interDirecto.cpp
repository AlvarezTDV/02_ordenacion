#include <iostream>
using namespace std;

//INICIALIZACION DE LAS FUNCIONES
void ingresarNumArreglo(int, int[]);
void mostrarArreglo(int, int[]);
void interDirDer(int, int[]);
void interDirIzq(int, int[]);

int main() {
	int numerosArreglo, arreglo[100], seleccion;
	cout << "Ingresa cuantos numeros tendra el arreglo (MAX 100): ";
	cin >> numerosArreglo;
	
	//CONDICION PARA COMPROBAR SI EL USUARIO NO SOBREPASO EL LIMITE
	if ( numerosArreglo > 100 ) {
		cout << "ERROR: SOBREPASO EL LIMITE" << endl;
	} else {
		ingresarNumArreglo(numerosArreglo, arreglo);
		cout << endl << "Arreglo ingresado: " << endl;
		mostrarArreglo(numerosArreglo, arreglo);
		cout << endl << "// TIPO DE INTERCAMBIO DIRECTO //" << endl;
		cout << "1. INTERCAMBIO DIRECTO POR LA DERECHA" << endl;
		cout << "2. INTERCAMBIO DIRECTO POR LA IZQUIERDA" << endl;
		cout << "3. INTERCAMBIO DIRECTO CON SEÑAL" << endl;
		cout << "4. INTERCAMBIO DIRECTO BIDIRECCIONAL" << endl;
		cin >> seleccion;
		
		//SWITCH PARA ESCOGER QUE TIPO DE INTERCAMBIO DESEA EL USUARIO
		switch( seleccion ) {
			case 1:
				interDirDer(numerosArreglo, arreglo);
				cout << endl << "Arreglo ordenado: " << endl;
				mostrarArreglo(numerosArreglo, arreglo);
				break;
			case 2:
				interDirIzq(numerosArreglo, arreglo);
				cout << endl << "Arreglo ordenado: " << endl;
				mostrarArreglo(numerosArreglo, arreglo);
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				cout << "ERROR: INGRESO UN NUMERO NO VALIDO" << endl;
		}
	}
}

//FUNCION PARA INGRESAR DATOS A UN ARREGLO
void ingresarNumArreglo(int numerosArreglo, int arreglo[100]) {
	for ( int i = 0; i < numerosArreglo; i++ ) {
		cout << "Ingresa el valor nro " << i+1 << ": ";
		cin >> arreglo[i];
	}
}

//FUNCION PARA MOSTRAR EL ARREGLO
void mostrarArreglo(int numerosArreglo, int arreglo[100]) {
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

//FUNCION INTERCAMBIO DIRECTO: POR LA IZQUIERDA
void interDirIzq(int numerosArreglo, int arreglo[100]) {
	int aux;
	for ( int i = 0; i < numerosArreglo-1; i++ ) {
		for ( int j = numerosArreglo-1; j > i; j-- ) {
			if ( arreglo[j] < arreglo [j-1] ) {
				aux = arreglo[j-1];
				arreglo[j-1] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
}
