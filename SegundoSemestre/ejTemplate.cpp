#include <iostream>
using namespace std;
#include "FraccionS.h"
template <class T>
T suma(T p1, T p2, T p3){
    T paso = p1+p2;
    return paso+p3; 
}
int main(){
int a=1, b=2,c=3,d;
double e=1.2, f = 3.1, g= 4.2, h;
string s1 = "hola ", s2="lola ", s3="bunny ", s4;
FraccionS f1(1,4), f2(2,4), f3(3,4),f4;
f4 = suma(f1,f2,f3);
f4.muestra();
cout<<suma(a,b,c)<<endl;
cout<<suma(e,f,g)<<endl;
cout<<suma(s1,s2,s3)<<endl;
    return 0;
}