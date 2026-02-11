//Eugenio Espeleta, Adrian Vazquez
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

bool validarCodigo(string expresion) {
    Stack<char> pila;eval
    
    for(int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];
        
        if(c == '(' || c == '{' || c == '[') {
            pila.push(c);
        }
    
        else if(c == ')' || c == '}' || c == ']') {
            if(pila.isEmpty()) {
                cout << "Error: Signo de cierre '" << c << "' sin apertura" << endl;
                return false;
            }
            
            char tope = pila.peak();
            
            if((c == ')' && tope == '(') ||
               (c == '}' && tope == '{') ||
               (c == ']' && tope == '[')) {
                pila.pop();
            } else {
                cout << "Error: Signo '" << c << "' no coincide con '" << tope << "'" << endl;
                return false;
            }
        }
    }
    
    if(!pila.isEmpty()) {
        cout << "Error: Faltan signos de cierre para: ";
        while(!pila.isEmpty()) {
            cout << pila.pop() << " ";
        }
        cout << endl;
        return false;
    }
    
    return true;
}

int main() {
    string linea;
    
    cout << "Ingresa una linea de codigo: ";
    getline(cin, linea);
    
    if(validarCodigo(linea)) {
        cout << " Los signos estan balanceados correctamente" << endl;
    } else {
        cout << " Hay errores en los signos de agrupacion" << endl;
    }
    
    return 0;
}