#include <iostream>
using namespace std;

//INICIALIZACION DE LAS FUNCIONES
void ingresarNumArreglo(int, int[]);
void mostrarArreglo(int, int[]);
void interDirDer(int, int[]);
void interDirIzq(int, int[]);
void interDirCen(int, int[]);
void interDirBi(int, int[]);

int main() {
	int numerosArreglo, arreglo[100], seleccion;
	cout << "Ingresa cuantos numeros tendra el arreglo (MAX 100): ";
	cin >> numerosArreglo;
	ingresarNumArreglo(numerosArreglo, arreglo);
	cout << endl << "Arreglo ingresado: " << endl;
	mostrarArreglo(numerosArreglo, arreglo);
	
	do {
		//CONDICION PARA COMPROBAR SI EL USUARIO NO SOBREPASO EL LIMITE
		if ( numerosArreglo > 100 ) {
			cout << "ERROR: SOBREPASO EL LIMITE" << endl;
		} else {
			cout << endl << "// TIPO DE INTERCAMBIO DIRECTO //" << endl;
			cout << "1. INTERCAMBIO DIRECTO POR LA DERECHA" << endl;
			cout << "2. INTERCAMBIO DIRECTO POR LA IZQUIERDA" << endl;
			cout << "3. INTERCAMBIO DIRECTO CON SENIAL" << endl;
			cout << "4. INTERCAMBIO DIRECTO BIDIRECCIONAL" << endl;
			cout << "5. SALIR" << endl;
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
					interDirCen(numerosArreglo, arreglo);
					cout << endl << "Arreglo ordenado: " << endl;
					mostrarArreglo(numerosArreglo, arreglo);
					break;
				case 4:
					interDirBi(numerosArreglo, arreglo);
					cout << endl << "Arreglo ordenado: " << endl;
					mostrarArreglo(numerosArreglo, arreglo);
					break;
				case 5:
					cout << endl << "// SALIENDO DEL PROGRAMA //" << endl;
					break;
				default:
					cout << "ERROR: INGRESO UN NUMERO NO VALIDO" << endl;
			}
		}
	} while ( seleccion != 5 );
	return 0;
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

//FUNCION INTERCAMBIO DIRECTO: CON SEÑAL
void interDirCen(int numerosArreglo, int arreglo[100]) {
	int cen = 1;
	int i = 0;
	int aux;
	while ( i <= numerosArreglo-1 && cen == 1 ) {
		cen = 0;
		for ( int j = 0; j < numerosArreglo-1-i; j++ ) {
			if ( arreglo[j] > arreglo[j+1] ) {
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
				cen = 1;
			}
		}
		i++;
	}
}

//FUNCION INTERCAMBIO DIRECTO: BIDIRECCIONAL
void interDirBi(int numerosArreglo, int arreglo[100]) {
	int aux;
	int izq = 0;
	int der = numerosArreglo - 1;
	int k = numerosArreglo - 1;
	while ( izq <= der ) {
		for ( int i = der; i >= izq; i-- ) {
			if ( arreglo[i-1] > arreglo[i] ) {
				aux = arreglo[i-1];
				arreglo[i-1] = arreglo[i];
				arreglo[i] = aux;
				k = i; 
			}
		}
		izq = k + 1;
		for ( int i = izq; i <= der; i++ ) {
			if ( arreglo[i-1] > arreglo[i] ) {
				aux = arreglo[i-1];
				arreglo[i-1] = arreglo[i];
				arreglo[i] = aux;
				k = i; 
			}
		}
		der = k - 1;
	}
}
