#include <iostream>
#include "Estudiante.h"
using namespace std;
int main(){
Estudiante e1("Juan","1234","ITC");
Persona p1 ("Jose", "567");
e1.muestra();
cout<<endl;
p1.muestra();
return 0;
}