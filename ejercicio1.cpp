#include <iostream>
using namespace std;

struct art {
	string cod;
	string desc;
	int prec;
	int cant;
};

void interDirDer(int, art[]);

int main() {
	art articulos[50];
	int n;
	cout << "Ingresa la cantidad de articulos que ingresaras: ";
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cout << endl << "Articulo Nro " << i+1 << ": " << endl;
		cout << "Ingresa el codigo del articulo: ";
		cin >> articulos[i].cod;
		cout << "Ingresa la descripcion del articulo: ";
		cin >> articulos[i].desc;
		cout << "Ingresa el precio del articulo: ";
		cin >> articulos[i].prec;
		cout << "Ingresa la cantidad del articulo: ";
		cin >> articulos[i].cant;
	}
	interDirDer(n, articulos);
	cout << endl << "Arreglo ordenado de forma descendente: " << endl << endl;
	for ( int i = 0; i < n; i++ ) {
		cout << "Articulo Nro " << i+1 << ": " << endl;
		cout << "Codigo: " << articulos[i].cod << endl;
		cout << "Descripcion: " << articulos[i].desc << endl;
		cout << "Precio: " << articulos[i].prec << endl;
		cout << "Cantidad: " << articulos[i].cant << endl << endl;
	}
	return 0;
}

void interDirDer(int n, art articulos[50]) {
	art aux;
	for ( int i = 0; i < n-1; i++ ) {
		for ( int j = 0; j < n-i-1; j++ ) {
			if ( (articulos[j].prec*articulos[j].cant) < (articulos[j+1].prec*articulos[j+1].cant) ) {
				aux = articulos[j];
				articulos[j] = articulos[j+1];
				articulos[j+1] = aux;
			}
		}
	}
}
