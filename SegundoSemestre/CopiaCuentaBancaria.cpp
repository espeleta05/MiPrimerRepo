#include <iostream>
#include <string>
#include <vector>
#include "CuentaBanc.h"
using namespace std;

int main (){
    int cant, numCta, opcion, i = 0, indice = 0;
    string nombre;
    double saldo;
    bool existe = false;

    cout << "Cuantas cuentas vas a dar de alta?: ";
    cin >> cant;

    // CuentaBanc arrCtas[cant]; //arreglo normal
    vector<CuentaBanc> cuentas; //vector de cuentas bancarias

    for (int i = 0; i < cant; i++) {
        cout << "Dame el numero de cta de la cuenta " << i + 1 << ": ";
        cin >> numCta;
        cout << "Dame el nombre del de la cuenta " << i + 1 << ": ";
        cin >> nombre;
        cout << "Dame el saldo de cta de la cuenta " << i + 1 << ": ";
        cin >> saldo;

        // arrCtas[i].setNumCta(numCta);
        // arrCtas[i].setNombre(nombre);
        // arrCtas[i].setSaldo(saldo);

        CuentaBanc cb(numCta, nombre, saldo);
        cuentas.push_back(cb);
    }

    CuentaBanc cb(246, "Karen", 400);
    cuentas.insert(cuentas.begin() + 1, cb);

    for (int i = 0; i < cuentas.size(); i++) {
        cout << cuentas[i].getNumCta() << endl;
        cout << cuentas[i].getNombre() << endl;
        cout << cuentas[i].getSaldo() << endl;
    }

    do {
        cout << "1. Selecciona\n";
        cout << "2. Deposita\n";
        cout << "3. Retira\n";
        cout << "4. Consulta Saldo\n";
        cout << "5. Terminar\n";
        cin >> opcion;

        if (opcion == 1) {
            existe = false;
            cout << "Dame el num de cuenta: ";
            cin >> numCta;
            i = 0;
            while (i < cuentas.size() && !existe) {
                if (cuentas[i].getNumCta() == numCta) {
                    existe = true;
                    indice = i;
                } else {
                    i++;
                }
            }
            if (!existe) {
                cout << "No existe la cuenta \n";
            } else {
                cout << "Cliente " << cuentas[indice].getNombre() << endl;
            }
        }
        if (opcion==2){
            if(existe){
                cout<<"Dame la cantidad a depositar:$";
                cin>>saldo;
                cuentas[indice].deposita(saldo);
            }else{
                cout<<"No se ha seleccionado la cuentas\n";
            }
        }
        if (opcion == 3){
            if(existe){
                cout<<"Dame la cantidad a retirar: $";
                cin>>saldo;
                if(!cuentas[indice].retira(saldo)){
                    cout<<"Saldo insuficiente\n";
                }
            }else{
                cout<<"No se ha seleccionado la cuenta\n";
            }
        }

        if (opcion == 4) {
            if (existe) {
                cout << "Saldo actual de la cuenta: $" << cuentas[indice].getSaldo() << endl;
            } else {
                cout << "No se ha seleccionado ninguna cuenta.\n";
            }
        }

    } while (opcion != 5);

    return 0;
}