/*
Siles Via y Rada Oliver Alé
Guevara Chamorro Augusto José
Anco Porras Jhean Pier Julio
*/
#include <iostream>
#include <string.h>

using namespace std;
void menu(int *&a);
void casos (int*&a);
void MostCliente();
void RegCliente();

struct Cliente{
  char nombre [30];
  char apellido[30];
  char dni [20];
  char telefono [15];
  char edad [5];

};
int n=0;
Cliente *clientes = NULL;

int main (){
	setlocale(LC_ALL,"spanish");
	int *opcion = new int;
	clientes = new Cliente[1]; 
	do{
		menu (opcion);
		casos (opcion);
	  system("pause");
	  system("cls");
	}while(*opcion!=3);
	delete[] clientes;
	delete opcion; 
	return 0;}
	
void RegCliente (){
  Cliente *temp = new Cliente[n + 1];
  for (int i = 0; i < n; i++) {
  temp[i] = clientes[i];
  }
	
  do {
    cin.ignore();
    cout << "Ingrese nombre del cliente (máximo 20 caracteres): ";
    cin.getline(temp[n].nombre, 30);
    if (strlen(temp[n].nombre) == 0) {
      cout << "El nombre no puede estar vacío. Inténtelo de nuevo."<<endl;
      }else 
        if(strlen(temp[n].nombre) > 20) {
          cout << "El nombre es demasiado largo. Debe tener un máximo de 20 caracteres."<<endl;
        }
    }while (strlen(temp[n].nombre) == 0 || strlen(temp[n].nombre) > 20);  
	
  do{
      cout<<"Ingrese apellido del cliente: ";
      cin.getline(temp[n].apellido,30);
      if(strlen(temp[n].apellido) == 0){
        cout << "El apellido no puede estar vacío. Inténtelo de nuevo."<<endl;
        }else
          if(strlen(temp[n].apellido) > 20)
            cout<<"El apellido es demasiado largo. Debe tener un máximo de 20 caracteres."<<endl;
  }while (strlen(temp[n].apellido) == 0 || strlen(temp[n].apellido) > 20); 
	
  do{
    cout<<"Ingrese DNI del cliente: ";
    cin.getline(temp[n].dni,20);
    if(strlen(temp[n].dni) == 0){
      cout << "El DNI no puede estar vacio . Inténtelo de nuevo."<<endl;
    }else
      if(strlen(temp[n].dni) > 8)
        cout<<"El DNI tienes demasiado caracteres. Debe tener un máximo de 8 caracteres."<<endl;
  }while(strlen(temp[n].dni) == 0 || strlen(temp[n].dni) > 8);
	
  do{
    cout<<"Ingrese telefono del cliente: ";
    cin.getline(temp[n].telefono,15);
    if(strlen(temp[n].telefono) == 0){
      cout << "El número de telefono no puede estar vacío. Inténtelo de nuevo."<<endl;
      }else
        if(strlen(temp[n].telefono) > 9)
          cout<<"El número de telefono es demasiado largo. Debe tener un máximo de 9 caracteres."<< endl;
  }while (strlen(temp[n].telefono) == 0 || strlen(temp[n].telefono) > 9);
	
  do{
    cout<<"Ingrese edad del cliente: ";
    cin.getline(temp[n].edad,5);
      if(strlen(temp[n].edad) == 0){
        cout << "La edad no puede estar vacío. Inténtelo de nuevo."<<endl;
        }else
          if(strlen(temp[n].edad) > 3)
            cout<<"La edad es demasiado largo. Debe tener máximo de 3 caracteres."<< endl;
  }while (strlen(temp[n].edad) == 0 || strlen(temp[n].edad) > 3);
  cout << "Cliente registrado con éxito." << endl;
  delete[] clientes;
  clientes = temp;
  n++;
  
}
void MostCliente(){
  string DNI;
  cout<<"Ingrese DNI de  la persona a consultar: ";
  cin >> DNI;
  for(int i=0; i < n; i++){
    if(DNI == clientes[i].dni){
      cout<<"Nombre: "<<clientes[i].nombre<<endl;
      cout<<"Apellido: "<<clientes[i].apellido<<endl;
      cout<<"DNI: "<<clientes[i].dni<<endl;
      cout<<"Telefono: "<<clientes[i].telefono<<endl;
      cout<<"Edad: "<<clientes[i].edad<<endl;
      return;
    }
  }
  cout<<"No es un cliente frecuente";
}

void menu(int *&a){
	do{
    cout<<"===== MENU DE OPCIONES ====="<<endl;
    cout<<"1.- Ingresar Cliente"<<endl;
    cout<<"2.- Consultar CLiente"<<endl;
    cout<<"3.- Salir"<<endl;
    cout<<"Ingrese Opcion: ";
    cin>>*a;
    if(*a<1 || *a>3)
      cout<<"Error.... Vuelva a Ingresar";
  }while(*a<1  || *a >3);
	return;
}

void casos (int*&a){
	switch(*a){
    case 1:{
        cout<<"MENU INGRESAR CLIENTE"<<endl;
        RegCliente();
      }break;
    case 2:{
        cout<<"MENU - CONSULTAR CLIENTE"<<endl;
        MostCliente();
      }break;
    case 3:{
        cout<<"Gracias.... Vuelva pronto"<<endl;
      }break;
  }
}
