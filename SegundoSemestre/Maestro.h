#include <iostream>
using namespace std;
#include "Persona.h"
class Maestro : public Persona{
private:
string depto;
public:
Maestro();
Maestro( string nom, string cel, string depto);
void setDepto(string dpto);
string getDepto();
void muestra();
};
void Maestro::muestra(){
cout<<nombre<<" "<<cel<<" "<<depto<<" "<<endl;
}
Maestro::Maestro():Persona(){
depto =" ";
}
Maestro::Maestro(string nom,string cel, string dep):Persona(nom,cel){
depto = dep;
}
void Maestro::setDepto(string dep){
depto = dep;
}
string Maestro::getDepto(){
return depto;
}