

#include "nashe.h"

int main()
{
    int opcion;
    do {
        nashe jofe;
        opcion = 1;
        cout << "0. Salir" << endl;
        cout << "1. Meter persona" << endl;
        cout << "2. Listar" << endl;
        cout << "3. Buscar registro" << endl;
        cout << "4. Eliminar archivo" << endl;
       
        cout << "Ingrese la opcion que desea: "; cin >> opcion;
        switch (opcion) {

        case 1:
           
            jofe.meter();
            break;
        case 2:
            jofe.listar();
            break;
        case 3:
            jofe.buscar_reg();
            break;
        case 4:
            jofe.eliminar_archivo();
            break;
        default:
            cout << "opcion no valida" << endl;
            break;
        case 0: opcion = 0; break;
        }
    } while (opcion > 0);
    return 0;
}


