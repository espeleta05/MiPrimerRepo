#include <iostream>
#include "Estudiante.h"
#include "Maestro.h"
using namespace std;
int main(){
Estudiante e1("Juan","1234","ITC");
Persona p1 ("Jose", "567");
Maestro m1("Maria", "555", "Mecanica");
Persona *arr[3];
arr[0] = &e1;
arr[1] = &p1;
arr[2] = &m1;
for(int i = 0;i<3;i++){
arr[i]->muestra();
cout<<endl;
}
/*e1.muestra();
cout<<endl;
p1.muestra();*/
return 0;
}