#include <iostream>
using namespace std;
#include "Salon.h"

int main(){
    int cantSalones, ram, nSalon, opcion = 1, i=0;
    string marca, sistOpe;
    Salon arrSalon[10];
    cout << "Cuantos salones quieres dar de alta? max 10: ";
    cin >> cantSalones;
    for(int i =0; i<cantSalones; i++){
        cout << "Dame la marca de la computadora del salon " << i+1 << ": ";
        cin >> marca;
        cout << "Dame el sistema operativo de la computadora del salon " << i+1 << ": ";
        cin >> sistOpe;
        cout << "Dame la Ram de la computadora del salon " << i+1 << ": ";
        cin >> ram;
        Computadora p(marca, sistOpe, ram);
        arrSalon[i].setCompu(p);
        cout<< "Dame el numero del salon " << i+1 << ": ";
        cin >> nSalon;
        arrSalon[i].setNumeroSalon(nSalon);
        
    }
    while(opcion!=4){
        cout << "1) Buscar por marca \n";
        cout << "2) Buscar por Sistema Operativo \n";
        cout << "3) Mostrar todos los salones \n";
        cout << "4) Terminar\n";
        cin >> opcion;
        if (opcion == 1) {
            cout << "Marca a buscar: ";
            cin >> marca;
            bool found = false;
            for (int i = 0; i < cantSalones; i++) {
                if (arrSalon[i].getCompu().getMarca() == marca) {
                    cout << "Salon: " << arrSalon[i].getNumeroSalon() << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No existe una computadora con esa marca.\n";
            }
        }
        if (opcion == 2){
            cout << "Sistema operativo a buscar: ";
            cin >> sistOpe;
            bool found = false;
            for (int i = 0; i < cantSalones; i++) {
                if (arrSalon[i].getCompu().getSistOpe() == sistOpe) {
                    cout << "Salon: " << arrSalon[i].getNumeroSalon() << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No existe una computadora con esa marca.\n";
            }
        }
        if (opcion ==3){
            for(int i =0; i<cantSalones; i++){
                cout << "\nSalon " << i+1 << ":\n";
                cout << "Numero de Salon: " << arrSalon[i].getNumeroSalon()<<endl;
                cout << "Marca de Computadora: "  << arrSalon[i].getCompu().getMarca()<<endl;
                cout << "Sistema Operativo de Computadora: " << arrSalon[i].getCompu().getSistOpe()<<endl;
                cout << "Ram de Computadora: " << arrSalon[i].getCompu().getRam()<< " GB" <<endl;
            }
        }
        if(opcion == 4){
            cout<<"Bye \n";
        }
    }
return 0;
}