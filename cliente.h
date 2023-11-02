#ifndef CLIENTE_H_INCLUED

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;


class clientes{
    public:
        char id_username[10], date_registration[15], cuenta[35], name[15];

    void altas();
	void consulta general ();
	void modificar();
	void bajas ();
	void consulta individual ();
};
#endif // CLIENTE_H_INCLUED

int dim1,dim2,dim3,dim4, opc=0;
//////////////////AGREGAR////////////////////////////////
void clientes::altas(){
    cout<<"ESCRIBE EL ID DEL CLIENTE: ";
    cin.getline(id_username, 10);
    cin.getline(id_username, 10);
    cout<<"ESCRIBE NOMBRE DEL CLIENTE: ";
    cin.getline(name,15);
    cout<<"ESCRIBE EL CORREO DEL CLIENTE: ";
    cin.getline(mail,35);
    cout<<"ESCRIBE LA FECHA DE REGISTRO DEL CLIENTE: ";
    cin.getline(date_registration,15);
    ofstream Archivo("clientes.dat",ios::binary);
    dim1 = strlen(id_username);// Leer la longitud de la cadena
    dim2 = strlen(name);
    dim3 = strlen(mail);
    dim4 = strlen(date_registration);
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&id_username, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&name, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&mail, dim3);
    Archivo.write((char*)&dim4, sizeof(int));
    Archivo.write((char*)&date_registration, dim4);

    Archivo.close();
}

//////////////////MOSTRAR////////////////////////////////
void clientes::Mostrar(){
	system("cls");

    ifstream archivo("clientes.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
            cout << "LISTA DE CLIENTES " << endl << endl;
		while(!archivo.eof()){
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tamaño de la cadena que se quiere leer
			archivo.read((char*)&id_username, dim1);
			id_username[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&name, dim2);
			name[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&mail, dim3);
			mail[dim3] = '\0';
			archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&date_registration, dim4);
			date_registration[dim4] = '\0';
            cout << id_username << "  " << name << "  " << mail << "  " << date_registration <<endl;
		}
	}
    archivo.close();
}

/////////////////MODIFICAR///////////////////////////////
void clientes::Modificar(){
    int band = 0;
    char id2[10];

	ifstream archivo("clientes.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else{
	    cout << "ESCRIBE EL ID DEL CLIENTE: ";
        cin.getline(id2, 10);
        cin.getline(id2, 10);
		while(!archivo.eof() && !band){
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&id_username, dim1);
            id_username[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&name, dim2);
            name[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&mail, dim3);
            mail[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
            archivo.read((char*)&date_registration, dim4);
            date_registration[dim4] = '\0';

            if(strcmp(id2, id_username) == 0)
            {
                cout << id_username << "  " << name << "  " << mail <<"  "<< date_registration << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1){
        ifstream archivo("clientes.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof()){
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&id_username, dim1);
            id_username[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&name, dim2);
            name[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&mail, dim3);
            mail[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
            archivo.read((char*)&date_registration, dim4);
            date_registration[dim4] = '\0';


            if(strcmp(id2, id_username) == 0){
                cout<<"ESCRIBE EL NUEVO ID DEL CLIENTE: ";
                cin.getline(id_username, 10);
                cin.getline(id_username, 10);
                cout<<"ESCRIBE EL NOMBRE DEL CLIENTE: ";
                cin.getline(name,15);
                cout<<"ESCRIBE EL MAIL DE CLIENTE: ";
                cin.getline(mail,35);
                 cout<<"ESCRIBE LA FECHA DE REGISTRO DEL CLIENTE: ";
                cin.getline(date_registration,15);
                dim1 = strlen(id_username);
                dim2 = strlen(name);
                dim3 = strlen(mail);
                dim4 = strlen(date_registration);
            }//condicion
            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&id_username, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&name, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&mail, dim3);
             temporal.write((char*)&dim4, sizeof(int));
            temporal.write((char*)&date_registration, dim4);
        }//ciclo while

	temporal.close();
	archivo.close();
	remove("clientes.txt");
	rename("temporal.txt", "clientes.txt");
	}//condicional de la opcion

    }// else

}

////////////////ELIMINAR/////////////////////////////////
void clientes::Eliminar(){
int band = 0;
    char id2[10];

	ifstream archivo("clientes.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else{
	    cout << "ID USERNAME DEL CLIENTE A ELIMINAR: ";
        cin.getline(id2, 10);
        cin.getline(id2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&id_username, dim1);
            id_username[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&name, dim2);
            name[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&mail, dim3);
            mail[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
            archivo.read((char*)&date_registration, dim4);
            date_registration[dim4] = '\0';

            if(strcmp(id2, id_username) == 0){
                cout << id_username << "  " << name << "  " << mail <<"  "<< date_registration << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR EL CLIENTE?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1){
        ifstream archivo("clientes.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof()){
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&id_username, dim1);
            id_username[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&name, dim2);
            name[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&mail, dim3);
            mail[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
            archivo.read((char*)&date_registration, dim4);
            date_registration[dim4] = '\0';

            if(strcmp(id2, id_username) != 0){
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&id_username, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&name, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&mail, dim3);
                temporal.write((char*)&dim4, sizeof(int));
                temporal.write((char*)&date_registration, dim4);
            }//condicion

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("clientes.txt");
	rename("temporal.txt", "clientes.txt");
	}//condicional de la opcion

    }//

}

///////////////BUSCAR////////////////////////////////////
void clientes::Buscar(){
    char id2[10];
    int band = 0;
    system("cls");

    ifstream archivo("clientes.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout << "ESCRIBE EL ID DEL CLIENTE A BUSCAR: ";
        cin.getline(id2, 10);
        cin.getline(id2, 10);
		while(!archivo.eof() && !band){
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tamaño de la cadena que se quiere leer
			archivo.read((char*)&id_username, dim1);
			id_username[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&name, dim2);
			name[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&mail, dim3);
			mail[dim3] = '\0';
			archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&date_registration, dim4);
			date_registration[dim4] = '\0';
			if( strcmp(id2, id_username) == 0){
                cout << id_username << "  " << name << "  " << mail <<"  "<< date_registration <<endl;
                band = 1;
            }
		}
		if (!band)
            cout << "NO SE ENCUENTRA EL CLIENTE" << endl;
	}
    archivo.close();
}

    
