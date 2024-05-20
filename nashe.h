#pragma once
#include "Persona.h"
class nashe
{
private:
	Persona* cima;
public:
	void meter();
	void guardar();
	void mostrar_registro(int);
	void listar();
	int buscar_reg();
	void eliminar_archivo();
};

