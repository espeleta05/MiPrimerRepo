#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;
class Taxi{
    private:
    Persona responsable;
    int ident;
    public:
    void setResponsable(Persona p);
    void setIdent(int id){ident = id;};
    Persona getResponsable(){return responsable;};
    int getIdent(){return ident;};

};
void Taxi::setResponsable(Persona p){
    responsable = p;
}