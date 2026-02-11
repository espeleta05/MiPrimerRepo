#include "Stack.h"
#include <iostream>
using namespace std;

int main(){
    Stack<char> miPila;

    miPila.push('a');
    miPila.push('b');
    miPila.push('c');
    
    cout<<miPila.peak()<<endl;

    miPila.print();

    cout<<endl<<miPila.pop()<<endl;

    miPila.print();

    return 0;
} 