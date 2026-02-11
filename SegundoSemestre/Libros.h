#include "MateriaDeLectura.h"
#include <iostream>
#include <string>

class Libro : public MateriaDeLectura
{
private:
    string editorial;
    int numPags;

public:
    Libro();
    Libro(string t, string a, string ed, int nP);
    void setEditorial(string ed) { editorial = ed; };
    string getEditorial() { return editorial; };
    void setNumeroPags(int nP) { numPags = nP; };
    int getNumPags() { return numPags; };
    void muestra();
};

Libro::Libro() : MateriaDeLectura()
{
    editorial = " ";
    numPags = 0;
}

Libro::Libro(string t, string a, string ed, int nP) : MateriaDeLectura(t, a)
{
    editorial = ed;
    numPags = nP;
}


void Libro::muestra(){
    cout<<"El libro con titulo: "<<titulo<<" del autor "<<autor<<" editorial "<<editorial<<" con "<<numPags<<" paginas\n";
}

