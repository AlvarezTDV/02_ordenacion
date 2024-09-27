#include <iostream>
using namespace std;

void ingresarNumArreglo(int, int[], int[]);
void mostrarArregloCop(int, int[]);
void mostrarArregloOri(int, int[]);
void reseteo(int, int[], int[]);
void metodoShell(int, int []);


int main() {
	int capacidad, arreglo[100], arreglo1[100], seleccion;
	cout << "Ingresa la capacidad del arreglo (max 100): ";
	cin >> capacidad;
	if ( capacidad > 100 ) {
		cout << "ERROR: SOBREPASO EL LIMITE" << endl;
	} else if ( capacidad <= 0) {
		cout << "ERROR: DEBE INGRESAR UN VALOR POSITIVO";
	} else {
		ingresarNumArreglo(capacidad, arreglo, arreglo1);
		cout << endl << "ARREGLO INGRESADO: " << endl;
		mostrarArregloOri(capacidad, arreglo);
		do {
			cout << endl << "ESCOGA UNA OPCION: " << endl;
			cout << "1. ORDENE EL ARREGLO CON EL METODO DE SHELL" << endl;
			cout << "2. ORDENE EL ARREGLO CON EL METODO RAPIDO" << endl;
			cout << "3. MOSTRAR EL ARREGLO ORIGINAL" << endl;
			cout << "4. SALIR" << endl;
			cin >> seleccion;
			switch ( seleccion ) {
				case 1:
					reseteo(capacidad, arreglo1, arreglo);
					cout << "ARREGLO ORDENADO CON EL METODO DE SHELL: " << endl;
					metodoShell(capacidad, arreglo1);
					mostrarArregloCop(capacidad, arreglo1);
					break;
				case 2:
					reseteo(capacidad, arreglo1, arreglo);
					cout << "ARREGLO ORDENADO CON EL METODO RAPIDO: " << endl;
					
					mostrarArregloCop(capacidad, arreglo1);
					break;
				case 3:
					cout << endl << "ARREGLO: " << endl;
					mostrarArregloOri(capacidad, arreglo);
					break;
				case 4:
					cout << "SALIENDO DEL PROGRAMA ..." << endl;
					break;
				default:
					cout << "ERROR: NUMERO INVALIDO" << endl;
					break;
			} 
		} while ( seleccion != 4 );
	}
	return 0;
}

//FUNCION PARA INGRESAR DATOS A UN ARREGLO
void ingresarNumArreglo( int capacidad, int arreglo[100], int arreglo1[100] ) {
	for ( int i = 0; i < capacidad; i++ ) {
		cout << "Ingresa el valor nro " << i+1 << ": ";
		cin >> arreglo[i];
		//DUPLICAMOS EL ARREGLO PARA EVITAR SUSTITUIR EL ARREGLO ORIGINAL
		arreglo1[i] = arreglo[i];
	}
}

//FUNCION PARA RESETEAR LOS DATOS DEL ARREGLO COPIA
void reseteo( int capacidad, int arreglo1[100], int arreglo[100] ) {
	for ( int i = 0; i < capacidad; i++ ) {
		arreglo1[i] = arreglo[i];
	}
}

//FUNCION PARA MOSTRAR EL ARREGLO ORIGINAL
void mostrarArregloOri( int capacidad, int arreglo[100] ) {
	for ( int i = 0; i < capacidad; i++ ) {
		cout << arreglo[i] << "  ";
	}
	cout << endl;
}

//FUNCION PARA MOSTRAR EL ARREGLO COPIADO
void mostrarArregloCop( int capacidad, int arreglo1[100] ) {
	for ( int i = 0; i < capacidad; i++ ) {
		cout << arreglo1[i] << "  ";
	}
	cout << endl;
}

//FUNCION METODO DE SHELL
void metodoShell( int capacidad, int arreglo1[100] ) {
	int aux, k, i, cen;
	k = capacidad + 1;
	while ( k > 1 ) {
		k = int(k/2);
		cen = 1;
		while ( cen == 1 ) {
			cen = 0;
			i = 0;
			while ( i + k < capacidad ) {
				if ( arreglo1[i+k] < arreglo1[i] ) {
					aux = arreglo1[i];
					arreglo1[i] = arreglo1[i+k];
					arreglo1[i+k] = aux;
					cen = 1;
				}
				i = i + 1;
			}
		}
	}
}
