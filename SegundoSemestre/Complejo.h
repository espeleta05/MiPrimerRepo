#include <iostream>
using namespace std;
class Complejo{
private:
double real;
double ima;
public:
Complejo();
Complejo(double pReal, double pIma);
double getReal();
double getIma();
void setIma(double pIma);
void setReal(double pReal);
Complejo suma(Complejo c);
Complejo resta(Complejo c);
Complejo operator+(Complejo c);
Complejo operator*(Complejo c);
bool operator==(Complejo c);
};
Complejo Complejo::operator+(Complejo c){
double realP = real+c.real;
double imaP = ima+c.ima;
Complejo c1(realP,imaP);
return c1;
}
Complejo Complejo::operator*(Complejo c){
double realP = (real*c.real - ima*c.ima);
double imaP = (ima*c.real + real*c.ima);
Complejo c1(realP,imaP);
return c1;
}
bool Complejo::operator==(Complejo c){
if(real==c.real && ima==c.ima){
return true;
} else {
return false;
}
}
Complejo::Complejo::Complejo(){
real = 0;
ima = 0;
}
Complejo::Complejo(double pReal, double pIma){
real = pReal;
ima = pIma;
}
double Complejo::getReal(){
return real;
}
double Complejo::getIma(){
return ima;
}
void Complejo::setReal(double pReal){
real = pReal;
}
void Complejo::setIma(double pIma){
ima = pIma;
}
Complejo Complejo::suma(Complejo c){
Complejo paso;
paso.real = real + c.real;
paso.ima = ima + c.ima;
return paso;
}
Complejo Complejo::resta(Complejo c){
Complejo paso;
paso.real = real - c.real;
paso.ima = ima - c.ima;
return paso;
}