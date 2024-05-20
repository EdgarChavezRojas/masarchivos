#include "Persona.h"
void Persona::archivear(ofstream& h) {
	h.write(reinterpret_cast<char*> (&nombre), sizeof(nombre));
	h.write(reinterpret_cast<char*> (&codigo), sizeof(codigo));
	h.write(reinterpret_cast<char*> (&apellido), sizeof(apellido));
	h.write(reinterpret_cast<char*> (&fechadenac), sizeof(fechadenac));
	h.write(reinterpret_cast<char*> (&genero), sizeof(genero));
	h.write(reinterpret_cast<char*> (&direccion), sizeof(direccion));
	h.write(reinterpret_cast<char*> (&telefono), sizeof(telefono));

}
bool Persona::leer(ifstream& o) {
	bool h = false;
	if (o.is_open() == true) {
		o.read(reinterpret_cast<char*> (&nombre), sizeof(nombre));
		if (o.eof() == false) {
			o.read(reinterpret_cast<char*> (&codigo), sizeof(codigo));
			o.read(reinterpret_cast<char*> (&apellido), sizeof(apellido));
			o.read(reinterpret_cast<char*> (&fechadenac), sizeof(fechadenac));
			o.read(reinterpret_cast<char*> (&genero), sizeof(genero));
			o.read(reinterpret_cast<char*> (&direccion), sizeof(direccion));
			o.read(reinterpret_cast<char*> (&telefono), sizeof(telefono));
			h = true;
		}
	}
	return h;
}
bool Persona::eliminar(fstream& i, int nro) {
	bool q = false;
	if (i.is_open() == true) {
		i.seekg(tam_reg() * (nro - 1), ios::beg);
				i.read(reinterpret_cast<char*> (&nombre), sizeof(nombre));
				if (i.eof() == false) {
					i.read(reinterpret_cast<char*> (&codigo), sizeof(codigo));
					i.read(reinterpret_cast<char*> (&apellido), sizeof(apellido));
					i.read(reinterpret_cast<char*> (&fechadenac), sizeof(fechadenac));
					i.read(reinterpret_cast<char*> (&genero), sizeof(genero));
					i.read(reinterpret_cast<char*> (&direccion), sizeof(direccion));
					i.read(reinterpret_cast<char*> (&telefono), sizeof(telefono));

					codigo = 0;
						i.seekp(tam_reg() * (nro - 1), ios::beg);
						i.write(reinterpret_cast<char*> (&nombre), sizeof(nombre));
						i.write(reinterpret_cast<char*> (&codigo), sizeof(codigo));
						i.write(reinterpret_cast<char*> (&apellido), sizeof(apellido));
						i.write(reinterpret_cast<char*> (&fechadenac), sizeof(fechadenac));
						i.write(reinterpret_cast<char*> (&genero), sizeof(genero));
						i.write(reinterpret_cast<char*> (&direccion), sizeof(direccion));
						i.write(reinterpret_cast<char*> (&telefono), sizeof(telefono));
						q = true;
				}
		}

	return q;
}
bool Persona::buscar(ifstream& o, int nro) {
	bool k = false;
	if (o.is_open() == true) {
		o.read(reinterpret_cast<char*> (&nombre), sizeof(nombre));
		o.read(reinterpret_cast<char*> (&codigo), sizeof(codigo));
		o.read(reinterpret_cast<char*> (&apellido), sizeof(apellido));
		o.read(reinterpret_cast<char*> (&fechadenac), sizeof(fechadenac));
		o.read(reinterpret_cast<char*> (&genero), sizeof(genero));
		o.read(reinterpret_cast<char*> (&direccion), sizeof(direccion));
		o.read(reinterpret_cast<char*> (&telefono), sizeof(telefono));
		if (o.eof() == false) {
			k = true;
		}
		else {
			//cout << endl << "Registro no XX existe";
		}
	}
	else {
		cout << endl << "Arhivo no existe";
	}
	return(k);


}