//Adrian Vazquez y Eugenio Espeleta

//Analisis
//El programa convierte una expresion infija a notacion polaca inversa (postfija) utilizando una pila para manejar los operadores y paréntesis.
//El usuario ingresa una expresión infija, y el programa procesa cada token (número, operador, paréntesis) para construir la expresión en notación polaca inversa.
//El programa maneja la precedencia de los operadores y asegura que los paréntesis se procesen correctamente.
//Finalmente, muestra la expresión convertida y permite al usuario repetir el proceso si lo desea.

//Diseño
//1. Definir una función para determinar la precedencia de los operadores.
//2. Definir una función para verificar si un carácter es un operador.
//3. Implementar la función principal que convierte la expresión infija a notación polaca
//   inversa utilizando una pila para los operadores.
//4. En el main, solicitar al usuario la expresión infija, llamar a la función de conversión y mostrar el resultado.
//5. Permitir al usuario repetir el proceso si lo desea.
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infijaAPolacaInversa(const string& exp) {
    Stack<char> operadores;
    string salida;

    for (size_t i = 0; i < exp.length(); ++i) {
        char token = exp[i];

        if (isspace(token)) continue;

        if (isdigit(token)) {
            string numero;
            while (i < exp.length() && isdigit(exp[i])) {
                numero += exp[i];
                i++;
            }
            salida += numero + " ";
            i--; 
        }
        else if (isalpha(token)) {
            salida += token;
            salida += " ";
        }
        else if (token == '(') {
            operadores.push(token);
        }
        else if (token == ')') {
            while (!operadores.isEmpty() && operadores.peak() != '(') {
                salida += operadores.pop();
                salida += " ";
            }
            if (!operadores.isEmpty() && operadores.peak() == '(') {
                operadores.pop();
            }
        }
        else if (esOperador(token)) {
            while (!operadores.isEmpty() && precedencia(operadores.peak()) >= precedencia(token) && operadores.peak() != '(') {
                salida += operadores.pop();
                salida += " ";
            }
            operadores.push(token);
        }
    }

    while (!operadores.isEmpty()) {
        salida += operadores.pop();
        salida += " ";
    }

    if (!salida.empty() && salida.back() == ' ')
        salida.pop_back();

    return salida;
}

int main() {
    int opcion;
    do {
        string expresion;
        cout << "Introduce la expresion infija: ";
        cin.ignore();
        getline(cin, expresion);

        string polaca = infijaAPolacaInversa(expresion);
        cout << "Expresion en notacion polaca inversa: " << polaca << endl;

        cout << "\n¿Desea convertir otra expresion?\n1) Si\n2) No\nOpcion: ";
        cin >> opcion;
    } while (opcion == 1);

    return 0;
}