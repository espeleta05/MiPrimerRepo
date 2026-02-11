// main.cpp
#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int iMat[10][10];
    int iArr1[10], iArr2[10];
    int r, c, ren, col, tamArr1, tamArr2;

    cout << "MATRIZ ENTEROS" << endl;
    cout << "Filas (max 10): ";
    cin >> r;
    cout << "Columnas (max 10): ";
    cin >> c;

    llenarMatriz(iMat, r, c);

    cout << "Renglon a copiar (0-" << r-1 << "): ";
    cin >> ren;
    cout << "Columna a copiar (0-" << c-1 << "): ";
    cin >> col;

    copiarRenglon(iMat, r, c, ren, iArr1, tamArr1);
    copiarColumna(iMat, r, c, col, iArr2, tamArr2);

    cout << "Renglon copiado: ";
    mostrarArreglo(iArr1, tamArr1);
    cout << "Columna copiada: ";
    mostrarArreglo(iArr2, tamArr2);

    return 0;
}