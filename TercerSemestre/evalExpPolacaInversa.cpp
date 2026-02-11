#include <iostream>
using namespace std;

#include "stack.h"
#include <cmath>

int evalua(string exp){
    int resultado, val1, val2;
    string operadores = "+-*/^";
    Stack<int> miPila;
    for (int i=0; i<exp.length(); i++){
        int pos = operadores.find(exp[i]);
        if (pos == -1){
            miPila.push(exp[i]- 48);

        } else{
            val1 = miPila.pop();
            val2 = miPila.pop();
            if (exp[i]== '+'){
                resultado = val2+ val1;
            }
            if (exp[i]== '-'){
                resultado = val2 - val1;
            }
            if (exp[i]== '*'){
                resultado = val2 * val1;
            }
            if (exp[i]== '/'){
                resultado = val2 / val1;
            }
            if (exp[i]== '^'){
                resultado = pow(val2, val1);
            }
            miPila.push(resultado);
        }
    }
    
    return miPila.pop();
}


int main(){
    int opcion;
    string expresion;
    do{
        cout<<"1) Evaluar expresion en notacion polaca inversa\n";
        cout<<"2) Salir\n";
        cin>>opcion;
        if (opcion==1){
            cout << "Dame la expresion: ";
            cin>>expresion;
            cout<<"El resultado es: "<<evalua(expresion)<<endl;
        }

    }while (opcion!=2);
    return 0;
}