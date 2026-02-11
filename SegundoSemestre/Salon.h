#include <iostream>
#include <string>
#include "Computadora.h"
using namespace std;

class Salon{
    private:
    Computadora compu;
    int nSalon;
    public:
    Salon();
    void setCompu(Computadora p);
    void setNumeroSalon(int num){nSalon = num;};
    Computadora getCompu(){return compu;};
    int getNumeroSalon(){return nSalon;};
};
Salon::Salon() {
    nSalon = 0;
};
void Salon::setCompu(Computadora p){
    compu = p;
}