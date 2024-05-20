#include "nashe.h"
void nashe::meter(){
	string nombre;
	int codigo;
	string apellido;
	string fechadenac;
	char genero;
	string direccion;
	string telefono;
	cout << "Digite nombre: "; cin.ignore(); getline(cin, nombre);
	cout << "Digite codigo: "; cin >> codigo; cin.ignore();
	cout << "Digite apellido: "; getline(cin, apellido);
	cout << "Digite fecha de nacimiento: "; getline(cin, fechadenac);
	cout << "Digite genero(M/F): "; cin >> genero; cin.ignore();
	cout << "Digite direccion: "; getline(cin, direccion);
	cout << "Digite telefono: "; getline(cin, telefono); cin.ignore();
	Persona* aux = new Persona(nombre, codigo, apellido, fechadenac, genero, direccion, telefono);
	aux->siguiente = cima;
	cima = aux;
	guardar();
}
void nashe::guardar() {
	ofstream archivo("clase.bin", ios::app | ios::binary);
	Persona* si = cima;
	si->archivear(archivo);
	archivo.close();

}
void nashe::listar() {
	int cr = 0;
	cima = new Persona();
	ifstream archivo("clase.bin", ios::in | ios::binary);
	while (cima->leer(archivo) == true) {
		cr++;
		if (cima->get_codigo() != 0) {
			mostrar_registro(cr);
		}
	}
}
void nashe::mostrar_registro(int nro) {
	cout << "Registro: " << nro << endl;
	cout << "Nombre: " << cima->get_nombre()<<endl;
	cout << "Codigo: " << cima->get_codigo()<<endl;
	cout << "Apellido: " << cima->get_apellido()<<endl;
	cout << "Fecha de nacimiento: " << cima->get_fechadenac()<<endl;
	cout << "Genero: " << cima->get_genero() << endl;
	cout << "Direccion: " << cima->get_direccion() << endl;
	cout << "Telefono: " << cima->get_telefono() << endl;
}
int nashe::buscar_reg() {
	int nroReg;
	cout << endl << endl << "Introducir numero de registro a buscar :  ";
	cin >> nroReg;
	cima = new Persona();
	ifstream fentrada("clase.bin", ios::in | ios::binary);
	if (cima->buscar(fentrada, nroReg) == true) {
		mostrar_registro(nroReg);
	}
	else {
		cout << endl << "Registro no existe";
		nroReg = -1;
	}
	fentrada.close();
	return(nroReg);

}
void nashe::eliminar_archivo() {

	int nroReg;
	nroReg = buscar_reg();
	if (nroReg > 0) {
		fstream fes("clase.bin", ios::in | ios::out | ios::binary);
		cima = new Persona();
		if (cima->eliminar(fes, nroReg) == true) {
			cout << endl << "Registro eliminado correctmente " << endl;
		}
		else {
			cout << endl << "Registro no existe pa eliminar" << endl;
		}
		fes.close();
	}

}