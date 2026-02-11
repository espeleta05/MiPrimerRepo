#include<iostream>
using namespace std;
class Rectangulo{
protected:
int ancho;
int largo;
public:
Rectangulo();
Rectangulo(int largoP,int anchoP);
void setAncho(int anchoP);
void setLargo(int largoP);
int getAncho();
int getLargo();
void dibuja();
int calculaArea();
~Rectangulo();
};
Rectangulo::Rectangulo(){
ancho = 1;
largo = 1;
}
Rectangulo::~Rectangulo(){
cout<<"llamada al destructor\n";
}
Rectangulo::Rectangulo(int largoP, int anchoP){
ancho = anchoP;
largo = largoP;
}
void Rectangulo::setAncho(int anchoP){
ancho = anchoP;
}
void Rectangulo::setLargo(int largoP){
largo = largoP;
}
int Rectangulo::calculaArea(){
return ancho*largo;
}
int Rectangulo::getAncho(){
return ancho;
}
int Rectangulo::getLargo(){
return largo;
}
void Rectangulo::dibuja()
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
for (int c = 2; c < largo; c++)
cout<<" ";
cout<<"*"<<endl;
}
}
}