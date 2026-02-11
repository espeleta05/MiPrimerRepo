#include <iostream>
using namespace std;
#include "Persona.h"
class Estudiante : public Persona{
private:
string carrera;
public:
Estudiante();
Estudiante( string nom, string cel, string carr);
void setCarrera(string carr);
string getCarrera();
void muestra();
};
void Estudiante::muestra(){
cout<<nombre<<" "<<cel<<" "<<carrera<<" "<<endl;
}
Estudiante::Estudiante():Persona(){
carrera =" ";
}
Estudiante::Estudiante(string nom,string cel, string carr):Persona(nom,cel){
carrera = carr;
}
void Estudiante::setCarrera(string carr){
carrera = carr;
}
string Estudiante::getCarrera(){
return carrera;
}