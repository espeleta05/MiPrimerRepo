#include <iostream>
using namespace std;

int main() {
    char nombreCompleto[20] ;  
    char nombre[20] ;          
    int i = 0;

    cout << "Por favor, ingresa tu nombre completo: ";
    cin.getline(nombreCompleto, 20);
    
    while (i < 19 && nombreCompleto[i] != ' ' && nombreCompleto[i] != '\0') {
        nombre[i] = nombreCompleto[i];
        i++;
    }
    nombre[i] = '\0'; 
    cout << "Hola " << nombre << " !!!" << endl;

    return 0;
}