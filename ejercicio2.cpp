#include <iostream>
using namespace std;

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct personal{
	string dni;
	string nombres;
	fecha nacimiento;
};

void seleccionDir(int, personal[]);
bool compararFechas(personal, personal);

int main() {
	int n;
	personal personas[50];
	cout << "Ingresa la cantidad de personas que va a ingresar: ";
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cout << endl << "Persona Nro " << i+1 << ": " << endl;
		cout << "Ingresa el DNI: ";
		cin >> personas[i].dni;
		cout << "Ingresa los nombres: ";
		cin.ignore();
		getline(cin, personas[i].nombres);
		cout << "Ingresa su fecha de nacimiento" << endl;
		cout << "Anio: ";
		cin >> personas[i].nacimiento.anio;
		cout << "Mes: ";
		cin >> personas[i].nacimiento.mes;
		cout << "Dia: ";
		cin >> personas[i].nacimiento.dia;
	}
	seleccionDir(n, personas);
	cout << endl << "Arreglo ordenado por fechas: " << endl;
	for ( int i = 0; i < n; i++ ) {
		cout << endl << "Persona Nro " << i+1 << ": " << endl;
		cout << "DNI: " << personas[i].dni << endl;
		cout << "Nombres: " << personas[i].nombres << endl;
		cout << "Fecha de nacimiento: " << endl;
		cout << "Dia: " << personas[i].nacimiento.dia << endl;
		cout << "Mes: " << personas[i].nacimiento.mes << endl;
		cout << "Anio: " << personas[i].nacimiento.anio << endl << endl;
	}
	return 0;
}

void seleccionDir(int n, personal personas[50]) {
	int k;
	personal menor;
	for ( int i = 0; i < n; i++ ) {
		menor = personas[i];
		k = i;
		for ( int j = i + 1; j < n; j++ ) {
			if ( compararFechas(personas[j], menor) ) {
				menor = personas[j];
				k = j;
			}
		}
		personas[k] = personas[i];
		personas[i] = menor;
	}
}

bool compararFechas(personal p1, personal p2) {
    if (p1.nacimiento.anio != p2.nacimiento.anio) {
        return p1.nacimiento.anio < p2.nacimiento.anio;
    }
    if (p1.nacimiento.mes != p2.nacimiento.mes) {
        return p1.nacimiento.mes < p2.nacimiento.mes;
    }
    return p1.nacimiento.dia < p2.nacimiento.dia;
}
