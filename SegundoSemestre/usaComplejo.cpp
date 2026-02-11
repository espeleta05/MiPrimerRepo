#include <iostream>
using namespace std;

#include "Complejo.h"

int main()
{
    Complejo cA;
    double real, ima;
    cout << "Dame el valor real del cB: ";
    cin >> real;
    cout << "Dame el valor imaginario del cB: ";
    cin >> ima;
    Complejo cB(real, ima);
    cout << "Dame el valor real del cC: ";
    cin >> real;
    cout << "Dame el valor imaginario del cC: ";
    cin >> ima;
    Complejo cC(real, ima);
    Complejo cD;
    cD = cB.suma(cC);
    Complejo cE;
    cE = cB.resta(cC);

    cout << "Complejo A(" << cA.getReal() << "," << cA.getIma() << ")\n";
    cout << "Complejo B(" << cB.getReal() << "," << cB.getIma() << ")\n";
    cout << "Complejo C(" << cC.getReal() << "," << cC.getIma() << ")\n";
    cout << "Complejo D suma de b+c (" << cD.getReal() << "," << cD.getIma() << ")\n";
    cout << "Complejo E resta de b-c (" << cE.getReal() << "," << cE.getIma() << ")\n";

    return 0;
}