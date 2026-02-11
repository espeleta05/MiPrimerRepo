// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;

template <class T>
void copiarRenglon(T mat[10][10], int r, int c, int ren, T arr[], int& tamArr) {
    tamArr = 0;
    for (int i = 0; i < c; i++) {
        arr[tamArr] = mat[ren][i];
        tamArr++;
    }
}

template <class T>
void copiarColumna(T mat[10][10], int r, int c, int col, T arr[], int& tamArr) {
    tamArr = 0;
    for (int i = 0; i < r; i++) {
        arr[tamArr] = mat[i][col];
        tamArr++;
    }
}

template <class T>
void llenarMatriz(T mat[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Ingresa el valor para [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

template <class T>
void mostrarArreglo(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif