#include <iostream>
using namespace std;
#include "Reloj.h"

int main(){
    Reloj hrInicial, hrFinal;
    int hora, minu;

    cout << "Ingrese la hora inicial (0-23): ";
    cin >> hora;
    cout << "Ingrese los minutos iniciales (0-59): ";
    cin >> minu;

    hrInicial.setHora(hora);
    hrInicial.setMinu(minu);

    cout << "Ingrese la hora final (0-23): ";
    cin >> hora;
    cout << "Ingrese los minutos finales (0-59): ";
    cin >> minu;

    hrFinal.setHora(hora);
    hrFinal.setMinu(minu);
    
    cout << "Hora inicial: ";
    hrInicial.muestra();
    cout << "Hora Final: ";
    hrFinal.muestra();
    return 0; 
}