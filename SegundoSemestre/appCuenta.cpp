#include <iostream>
using namespace std;
#include "Chequera.h"
int main()
{
    CuentaBanc *listaCtas[20];
    int sizeCtas;
    char tipoCta;
    int numCta;
    double saldoI, com, dinero;
    char opcion;
    cout << "Cuantas cuentas bancarias hay? ";
    cin >> sizeCtas;
    for (int c = 0; c < sizeCtas; c++)
    {
        cout << "Quieres una cuenta bancaria o de cheques? (b o c): ";
        cin >> tipoCta;
        cout << "Numero de cuenta? ";
        cin >> numCta;
        cout << "Saldo inicial? ";
        cin >> saldoI;
        if (tipoCta == 'c')
        {
            cout << "Comision por hacer retiro? ";
            cin >> com;
            listaCtas[c] = new Chequera(numCta, saldoI, com);
        }
        else
        {
            listaCtas[c] = new CuentaBanc(numCta, saldoI);
        }
    }
    do
    {
        cout << "\nMenu de opciones " << endl;
        cout << "a) depositar " << endl;
        cout << "b) retirar " << endl;
        cout << "c) consultar saldo " << endl;
        cout << "d) terminar " << endl;
        cout << "opcion -> ";
        cin >> opcion;
        switch (opcion)
        {
        case 'a':
        {
            cout << "Teclea el numero de cuenta: ";
            cin >> numCta;
            cout << "Cuanto vas a depositar? ";
            cin >> dinero;
            for (int i = 0; i < sizeCtas; i++)
            {
                if (listaCtas[i]->getNumCta() == numCta)
                {
                    listaCtas[i]->deposita(dinero);
                    break;
                }
            }
            break;
        }
        case 'b':
        {
            cout << "Teclea el numero de cuenta: ";
            cin >> numCta;
            cout << "Cuanto vas a retirar? ";
            cin >> dinero;
            for (int i = 0; i < sizeCtas; i++)
            {
                if (listaCtas[i]->getNumCta() == numCta)
                {
                    listaCtas[i]->retira(dinero);
                    break;
                }
            }
            break;
        }
        case 'c':
        {
            cout << "Teclea el numero de cuenta: ";
            cin >> numCta;
            for (int i = 0; i < sizeCtas; i++)
            {
                if (listaCtas[i]->getNumCta() == numCta)
                {
                    listaCtas[i]->mostrar();
                    break;
                }
            }
            break;
        }
        }
    } while (opcion != 'd');
    for (int i = 0; i < sizeCtas; i++)
    {
        delete listaCtas[i];
    }
    return 0;
}