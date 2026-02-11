#ifndef Persona_H
#define Persona_H
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    string cel;
    static int contPer;

public:
    Persona();
    Persona(string nom, string celP);
    string getNombre() { return nombre; }
    string getCelular() { return cel; }
    void setNombre(string nom) { nombre = nom; }
    void setCelular(string celP) { cel = celP; }
    static int getContPer();
    virtual void muestra();
};

int Persona::contPer = 0;

Persona::Persona() {
    nombre = " ";
    cel = " ";
    contPer++;
}

Persona::Persona(string nom, string celP) {
    nombre = nom;
    cel = celP;
    contPer++;
}

int Persona::getContPer() {
    return contPer;
}
void Persona::muestra(){
    cout<<nombre<<" "<<cel<<" "<<endl;
}
#endif