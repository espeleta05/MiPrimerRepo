#include <iostream>
using namespace std;
#include "Reloj.h"

class Evento {
private:
    Reloj horaI;
    int duracion;
    string asunto;
public:
    Evento(Reloj h = Reloj(), int d = 0, string a = "") : horaI(h), duracion(d), asunto(a) {}
    void setHoraI(Reloj h) { horaI = h; }
    void setDuracion(int d) { duracion = d; }
    void setAsunto(string a) { asunto = a; }
    Reloj getHoraI() { return horaI; }
    int getDuracion() { return duracion; }
    string getAsunto() { return asunto; }
    void muestra() {
        cout << "Hora de inicio: ";
        horaI.muestra();
        cout << "Duracion: " << duracion << " minutos" << endl;
        cout << "Asunto: " << asunto << endl;
    }
};