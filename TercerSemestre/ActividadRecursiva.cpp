#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sumaAcumulativa(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumaAcumulativa(n - 1);
    }
}

string invertirCadena(string s) {
    if (s.length() == 0) {
        return s;
    } else {
        return invertirCadena(s.substr(1)) + s[0];
    }
}

bool esPalindromo(string palabra) {
    if (palabra.length() <= 1) {
        return true;
    }
    if (palabra[0] != palabra[palabra.length()-1]) {
        return false;
    }
    return esPalindromo(palabra.substr(1, palabra.length()-2));
}

void imprimirPatron(int filas, int actual = 1) {
    if (actual > filas) {
        return;
    }
    cout << string(2*actual-1, '*') << endl;
    imprimirPatron(filas, actual+1);
}

int main() {
    char continuar = 's';
    
    while (continuar == 's' || continuar == 'S') {
        
        cout << "\n=== MENU DE OPERACIONES RECURSIVAS ===" << endl;
        cout << "1. Suma acumulativa" << endl;
        cout << "2. Invertir una palabra" << endl;
        cout << "3. Verificar si es palindromo" << endl;
        cout << "4. Imprimir patron de asteriscos" << endl;
        cout << "5. Salir" << endl;
        
        int opcion;
        cout << "\nElige una opcion (1-5): ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: {
                int num;
                cout << "Dame un numero positivo: ";
                cin >> num;
                if (num < 0) {
                    cout << "El numero debe ser positivo!" << endl;
                } else {
                    cout << "Resultado: " << sumaAcumulativa(num) << endl;
                }
                break;
            }
            case 2: {
                string texto;
                cout << "Dame una palabra: ";
                cin.ignore(); 
                getline(cin, texto);
                cout << "Cadena invertida: " << invertirCadena(texto) << endl;
                break;
            }
            case 3: {
                string palabra;
                cout << "Dame una palabra: ";
                cin >> palabra;
                transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
                if (esPalindromo(palabra)) {
                    cout << "Es un palindromo!" << endl;
                } else {
                    cout << "No es un palindromo" << endl;
                }
                break;
            }
            case 4: {
                int niveles;
                cout << "Dame el numero de niveles: ";
                cin >> niveles;
                imprimirPatron(niveles);
                break;
            }
            case 5:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opcion no valida!" << endl;
        }
        
        cout << "\nDeseas hacer otra operacion? (s/n): ";
        cin >> continuar;
    }
    
    cout << "Programa terminado. Hasta luego!" << endl;
    return 0;
}