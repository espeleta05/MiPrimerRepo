#include <iostream>
using namespace std;
#include "Fracciones.h"
int main()
{
    int cant, num, den;
    cout << "Cuantas fracciones quieres evaluar?: ";
    cin >> cant;
    Fracciones arrFracc[cant];
    for (int i = 0; i < cant; i++)
    {
        cout << "Dame el numerador de la fraccion #" << i + 1 << ": ";
        cin >> num;
        cout << "Dame el denominador de la fraccion #" << i + 1 << ": ";
        cin >> den;
        arrFracc[i].setNum(num);
        arrFracc[i].setDen(den);
        
    }
    for (int i = 0; i < cant; i++)
    {
        cout << "El resultado de la fraccion" << arrFracc[i].getNum() << "/" << arrFracc[i].getDen() << " es: " << arrFracc[i].CalcValorReal() << endl;
    }
    return 0;
}