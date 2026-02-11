#include "Figura.h"

class Triangulo : public Figura{
    public:
    void dibuja();
};

void Triangulo::dibuja()
{
    cout <<" * " << endl;
    cout <<" ** " << endl;
    cout <<" * " << endl;
    cout <<" Coord( " << x << "," << y <<")"<< endl;
    cout << endl;
}