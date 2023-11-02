#include <iostream>
#include <string>
#include "cliente.h"

using namespace std;

int main(){
     int opc;
     cout << "  SHOP CUCEI                               " <<endl << endl;
     cout << "    CLIENTES   ";
    do{
        cout<<"\n 1.-AGREGAR CLIENTE \n 2.-MOSTRAR CLIENTE \n 3.-BUSCAR CLIENTE \n 4.-ELIMINAR CLIENTE \n 5.-MODIFICAR CLIENTE\n 6-SALIR \n";
        cout << "SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: c.Agregar();
                break;

            case 2:c.Mostrar();
                break;

            case 3:c.Buscar();
               break;

            case 4:c.Eliminar();
                break;

            case 5:c.Modificar();
                break;
        }

    }while(opc!=6);

    return 0;
}
