#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Persona
{
public:
	string nombre;
	int codigo;
	string apellido;
	string fechadenac;
	char genero;
	string direccion;
	string telefono;
	Persona* siguiente;
	Persona(string nombre,int codigo ,string apellido, string fechadenac, char genero,string direccion, string telefono){
		this->nombre = nombre;
		this->codigo = codigo;
		this->apellido = apellido;
		this->fechadenac = fechadenac;
		this->genero = genero;
		this->direccion = direccion;
		this->telefono = telefono;
		siguiente = NULL;
	}
	Persona() {
		siguiente = NULL;
		nombre = "";
		codigo = 0;
		apellido = "";
		fechadenac = "";
		genero = 's';
		direccion = "";
		telefono = "";

	}
	string get_nombre() {
		return nombre;
	}
	string get_apellido() {
		return nombre;
	}
	int get_codigo() {
		return codigo;
	}
	string get_fechadenac() {
		return fechadenac;
	}
	char get_genero() {
		return genero;
	}
	string get_direccion() {
		return direccion;
	}
	string get_telefono() {
		return telefono;
	}
	void archivear(ofstream&);
	bool leer(ifstream&);
	bool eliminar(fstream&, int);
	bool buscar(ifstream&, int);
	int tam_reg() {
		return (sizeof(nombre) + sizeof(codigo) + sizeof(apellido) + sizeof(fechadenac) + sizeof(genero) + sizeof(direccion) + sizeof(telefono));
	}

};

