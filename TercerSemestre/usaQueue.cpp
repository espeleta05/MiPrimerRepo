#include <iostream>
using namespace std;

#include "Queue.h"

int main(){
    Queue<string> mifila;

    mifila.enqueue("Jose");
    mifila.enqueue("Juan");
    mifila.enqueue("Gabriel");
    mifila.enqueue("Baruc");
    mifila.enqueue("Lenin");
    mifila.enqueue("Palermo");
    cout<<"Mi fila tiene"<<mifila.getSize()<<" nombres"<<endl;
    cout<<"Y sus elementos son: \n";
    mifila.print();
    cout<<endl;
    cout<<"al inicio esta "<<mifila.front()<<endl;
    cout<<"al final esta "<<mifila.back()<<endl;
    cout<<"sacando el primer valor de la fila"<<mifila.dequeue()<<endl;
    mifila.print();

    return 0;   
}