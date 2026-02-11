#include "Figura.h"

class Cuadrado : public Figura{
    public:
    void dibuja();
};

void Cuadrado::dibuja()
{
    cout <<" ** " << endl;
    cout <<" ** " << endl;
    cout <<" ** " << endl;
    cout <<" Coord( " << x << "," << y <<")"<< endl;
    cout << endl;
}