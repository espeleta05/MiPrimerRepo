#include <iostream>
using namespace std;
#include "Rectangulo.h"

int main()
{
    Rectangulo arrRec[5];
    int largo, ancho;
    for (int i = 0; i < 5; i++)
    {
        cout << "Dame el largo del rect [" << i + 1 << "] ";
        cin >> largo;
        cout << "Dame el ancho del rect [" << i + 1 << "] ";
        cin >> ancho;
        arrRec[i].setLargo(largo);
        arrRec[i].setAncho(ancho);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Rect[" << i + 1 << "] tiene el largo de: " << arrRec[i].getLargo() << " y el ancho: " << arrRec[i].getAncho()<<" y su area es: "<<arrRec[i].calculaArea()<<endl;
    }

    return 0;
}