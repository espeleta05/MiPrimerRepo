#include <iostream>
#include <string>
using namespace std;

#include "CuentaBanc.h"

int main()
{
    int cant, numCta, opcion, indice = -1;
    string nombre;
    double cantidad, saldo;
    bool existe = false;

    cout << "Cuantas cuentas vas a dar de alta? ";
    cin >> cant;
    
    CuentaBanc* arrCtas = new CuentaBanc[cant];
    
    for (int i = 0; i < cant; i++)
    {
        cout << "Dame el numero de la cuenta " << i + 1 << " ";
        cin >> numCta;
        cout << "Dame el nombre del cliente de la cuenta " << i + 1 << " ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Dame el saldo de la cuenta " << i + 1 << " $";
        cin >> saldo;
        arrCtas[i].setNumCta(numCta);
        arrCtas[i].setNombre(nombre);
        arrCtas[i].setSaldo(saldo);
    }
    
    for (int i = 0; i < cant; i++)
    {
        cout << "Cuenta " << i + 1 << ":\n";
        cout << "Num de cuenta: " << arrCtas[i].getNumCta() << endl;
        cout << "Nombre del cliente: " << arrCtas[i].getNombre() << endl;
        cout << "Saldo de la cuenta: " << arrCtas[i].getSaldo() << endl;
    }
    
    do
    {
        cout << "1. Selecciona\n";
        cout << "2. Deposita\n";
        cout << "3. Retira\n";
        cout << "4. Consulta\n";
        cout << "5. Terminar\n";
        cin >> opcion;

        if (opcion == 1)
        {
            cout << "Dame el num de cuenta ";
            cin >> numCta;
            existe = false;
            for (int i = 0; i < cant; i++)
            {
                if (arrCtas[i].getNumCta() == numCta)
                {
                    existe = true;
                    indice = i;
                    break;
                }
            }
            if (!existe)
            {
                cout << "No existe la cuenta \n";
            }
            else
            {
                cout << "Cliente " << arrCtas[indice].getNombre() << endl;
            }
        }
        else if (opcion == 2)
        {
            if (indice != -1)
            {
                cout << "Dame la cantidad a depositar ";
                cin >> saldo;
                arrCtas[indice].deposita(saldo);
            }
            else
            {
                cout << "No se ha seleccionado la cuenta \n";
            }
        }
        else if (opcion == 3)
        {
            if (indice != -1)
            {
                cout << "Dame la cantidad a retirar ";
                cin >> saldo;
                if (!arrCtas[indice].retira(saldo))
                {
                    cout << "Saldo insuficiente \n";
                }
            }
            else
            {
                cout << "No se ha seleccionado la cuenta \n";
            }
        }
        else if (opcion == 4)
        {
            if (indice != -1)
            {
                cout << "Saldo actual: " << arrCtas[indice].getSaldo() << endl;
            }
            else
            {
                cout << "No se ha seleccionado la cuenta \n";
            }
        }
    } while (opcion != 5);
    
    return 0;
}
