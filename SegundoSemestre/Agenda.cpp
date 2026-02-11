#include <iostream>
#include "Evento.h"

using namespace std;

int main() {
    int eventos, hrs, min, duracion;
    string asunto;
    cout << "Cuantos eventos: ";
    cin >> eventos;
    Evento arrEventos[eventos];
    for (int i = 0; i < eventos; i++) {
        cout << "\nEvento " << i + 1 << endl;
        cout << "Horas de inicio: ";
        cin >> hrs;
        cout << "Minutos de inicio: ";
        cin >> min;
        Reloj r(hrs, min);
        cout << "Duracion (en minutos): ";
        cin >> duracion;
        cout << "Asunto: ";
        cin.ignore();
        getline(cin, asunto);
        arrEventos[i].setHoraI(r);
        arrEventos[i].setDuracion(duracion);
        arrEventos[i].setAsunto(asunto);
    }
    cout << "\nEventos registrados:\n";
    for (int i = 0; i < eventos; i++) {
        cout << "\nEvento " << i + 1 << endl;
        arrEventos[i].muestra();
    }
    return 0;
}