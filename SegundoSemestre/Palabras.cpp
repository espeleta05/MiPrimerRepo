#include <iostream>
using namespace std;

int main() {
    char palabra1[20], palabra2[20], palabra3[20];
    char temp[20] ;
    int i = 0;

    cout << "Ingrese la primera palabra: ";
    cin >> palabra1;
    cout << "Ingrese la segunda palabra: ";
    cin >> palabra2;
    cout << "Ingrese la tercera palabra: ";
    cin >> palabra3;

    
    i = 0;
    bool intercambiar = false;
    while (palabra1[i] != '\0' || palabra2[i] != '\0') {
        if (palabra1[i] > palabra2[i]) {
            intercambiar = true;
            break;
        }
        else if (palabra1[i] < palabra2[i]) {
            intercambiar = false;
            break;
        }
        i++;
    }
    if (intercambiar || (palabra1[i] != '\0' && palabra2[i] == '\0')) {
        i = 0;
        while (i < 20) {
            temp[i] = palabra1[i];
            palabra1[i] = palabra2[i];
            palabra2[i] = temp[i];
            if (palabra1[i] == '\0' && palabra2[i] == '\0') {
                i = 20; 
            }
            else {
                i++;
            }
        }
    }

    i = 0;
    intercambiar = false;
    while (palabra1[i] != '\0' || palabra3[i] != '\0') {
        if (palabra1[i] > palabra3[i]) {
            intercambiar = true;
            break;
        }
        else if (palabra1[i] < palabra3[i]) {
            intercambiar = false;
            break;
        }
        i++;
    }
    if (intercambiar || (palabra1[i] != '\0' && palabra3[i] == '\0')) {
        i = 0;
        while (i < 20) {
            temp[i] = palabra1[i];
            palabra1[i] = palabra3[i];
            palabra3[i] = temp[i];
            if (palabra1[i] == '\0' && palabra3[i] == '\0') {
                i = 20;
            }
            else {
                i++;
            }
        }
    }

    
    i = 0;
    intercambiar = false;
    while (palabra2[i] != '\0' || palabra3[i] != '\0') {
        if (palabra2[i] > palabra3[i]) {
            intercambiar = true;
            break;
        }
        else if (palabra2[i] < palabra3[i]) {
            intercambiar = false;
            break;
        }
        i++;
    }
    if (intercambiar || (palabra2[i] != '\0' && palabra3[i] == '\0')) {
        i = 0;
        while (i < 20) {
            temp[i] = palabra2[i];
            palabra2[i] = palabra3[i];
            palabra3[i] = temp[i];
            if (palabra2[i] == '\0' && palabra3[i] == '\0') {
                i = 20;
            }
            else {
                i++;
            }
        }
    }

    cout << "\nPalabras ordenadas:\n";
    cout << palabra1 << endl;
    cout << palabra2 << endl;
    cout << palabra3 << endl;

    return 0;
}