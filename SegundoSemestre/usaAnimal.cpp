#include <iostream>
#include "Perro.h"
#include "Gato.h"
using namespace std;
int main(){
Gato g1("Silvestre", 1947);
Perro p1("Fido", 2000);
Gato g2("Tom",1940);
Animal *arr[3];
arr[0] = &g1;
arr[1] = &p1;
arr[2] = &g2;
for(int i = 0;i<3;i++){
arr[i]->muestra();
arr[i]->habla();
cout<<endl;
}
return 0;
}