#include <iostream>
using namespace std;

template <class T>
T suma(T v1, T v2, T v3){
    return v1+v2+v3;
}


int main(){
    int a=1, b=2, c=3, d;
    double e=1.1, f=2.1, g=1.3, h;
    string i="hola ", j="lola ", k="bunny ", l;
    d= suma(a,b,c);
    cout<<d<<endl;
    h=suma(e,f,g);
    cout<<h<<endl;
    l=suma(i,j,k);
    cout<<l<<endl;


    return 0;
}