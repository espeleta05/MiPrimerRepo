#include <iostream>
#include "Rectangulo.h"
#include <string>
using namespace std;
class RectName: public Rectangulo{
private:
string name;
public:
RectName();
RectName(int la, int an, string n);
string getName(){return name;};
void setName(string n){name = n;};
void dibuja();
};
RectName::RectName():Rectangulo(){
name = " ";
}
RectName::RectName(int la, int an, string n):Rectangulo(la,an){
name = n;
}
void RectName::dibuja()
{ for (int r = 1; r <= ancho; r++)
{ // dibujo completo el primero y el ultimo renglon
if (r == 1 || r == ancho)
{ for (int c = 1; c <= largo; c++)
cout<<"*";
cout<<endl;
}
else
{
// dibujo solo los caracteres de los extremos en los renglones del medio
cout<<"*";
cout<<name;
for (int c = 2; c < largo; c++)
cout<<" ";
cout<<"*"<<endl;
}
}
}