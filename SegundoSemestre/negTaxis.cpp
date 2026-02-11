#include <iostream>
#include <string>
#include "Taxi.h"
using namespace std;
int main(){
int cantTaxis, ident,opcion = 1,i =0;
string nombre,cel;
Taxi arrTaxi[10];
cout<<"Cuantos taxis quieres dar de alta?: ";
cin>>cantTaxis;
for (int i = 0;i<cantTaxis;i++){
    cout<<"Dame el nombre de la persona responsable del taxi #"<<i+1<<" : ";
    cin>>nombre;
    cout<<"Dame el celular del responsable del taxi #"<<i+1<<" : ";
    cin>>cel;
    Persona p(nombre, cel);
    arrTaxi[i].setResponsable(p);
    cout<<"Dame el identificador del Taxi #"<<i+1<<" : ";
    cin>>ident;
    arrTaxi[i].setIdent(ident);
}
while(opcion!=4){
    cout<<"1) Listado de Taxis\n"<<endl;
    cout<<"2) Listado dado un Responsable\n"<<endl;
    cout<<"3) Dar de alta un taxi\n"<<endl;
    cout<<"4) Salir\n"<<endl;
    cin>>opcion;
    if(opcion == 1){
        for(int i =0;i<cantTaxis;i++){
            cout<<"Taxi #"<<i+1<<" : \n";
            cout<<"Responsable: "<<arrTaxi[i].getResponsable().getNombre()<<endl;
            cout<<"Celular :"<<arrTaxi[i].getResponsable().getCelular()<<endl;
            cout<<"Identificador: "<<arrTaxi[i].getIdent()<<endl; 
        }

    }
    if (opcion ==2){
        cout<<"Nombre a buscar";
        cin>>nombre;
        while(arrTaxi[i].getResponsable().getNombre()!=nombre && i<cantTaxis){
            i++;
        }
        if(i==cantTaxis){
            cout<<"No existe nombre \n";

        } else {
            cout<<"Responsable: "<<arrTaxi[i].getResponsable().getNombre()<<endl;
            cout<<"Celular :"<<arrTaxi[i].getResponsable().getCelular()<<endl;
            cout<<"Identificador: "<<arrTaxi[i].getIdent()<<endl; 
        }

    }
    if (opcion ==3){
        cout<<"Dame el nombre de la persona responsable del taxi #"<<cantTaxis+1;
    cin>>nombre;
    cout<<"Dame el celular del responsable del taxi #"<<cantTaxis+1;
    cin>>cel;
    Persona p(nombre, cel);
    arrTaxi[cantTaxis].setResponsable(p);
    cout<<"Dame el identificador del Taxi "<<cantTaxis+1;
    cin>>ident;
    arrTaxi[cantTaxis].setIdent(ident);
    cantTaxis++;
    }
if(opcion == 4){
    cout<<"Bye \n";
}
}
return 0;
}