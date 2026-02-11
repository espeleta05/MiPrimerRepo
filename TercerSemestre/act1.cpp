#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "calificacion.h"

int main() {
    calificacion arr[20];
    ifstream archEnt;
    ofstream archSal;
    double act, ex, proy;
    int i = 0;
    int salir;
    string nombre;
    archEnt.open("califica.txt");
    while (archEnt >> nombre >> act >> proy >> ex) {
        arr[i].setName(nombre);
        arr[i].setCalAct(act);
        arr[i].setCalEx(ex);
        arr[i].setCalProy(proy);
        i++;

    }

    archEnt.close();
    archSal.open("alumnos85.txt");
    
    do {
        cout << "1) Listado de alumnos\n";
        cout << "2) Alumnos con calif final > 85\n";
        cout << "3) Salir\n";
        cin >> salir;
        if (salir==1) {
            for (int j=0; j<i; j++){
                cout << arr[j].getName() << " " << arr[j].getCalAct() << " " << arr[j].getCalProy() << " " << arr[j].getCalEx() << " " << arr[j].calculaCalif() << endl;
            }
        }
        if (salir==2) {
            for (int j=0; j<i; j++){
                if (arr[j].calculaCalif() > 85) {
                    cout << arr[j].getName() << " " << arr[j].getCalAct() << " " << arr[j].getCalProy() << " " << arr[j].getCalEx() << " " << arr[j].calculaCalif() << endl;
                    archSal << arr[j].getName() << " " << arr[j].getCalAct() << " " << arr[j].getCalProy() << " " << arr[j].getCalEx() << " " << arr[j].calculaCalif() << endl;
            }
        }
    }
    } 
    while (salir != 3);
    return 0;
}