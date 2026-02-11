#ifndef CuentaBanc_H
#define CuentaBanc_H
#include <iostream>
#include <string>
using namespace std;
class CuentaBanc{
    protected:
    int numCta;
    double saldo;
    string nombre;
    public:
    CuentaBanc();
    CuentaBanc(int n, string nom, double s);
    void setNumCta(double nc);
    void setSaldo(double saldo);
    void setNombre(string nom){nombre = nom;};
    double getNumCta();
    double getSaldo();
    string getNombre(){return nombre;};
    virtual bool retira(double cant);
    void deposita(double cant);
    virtual void mostrar();
};
CuentaBanc::CuentaBanc(){
numCta = 0;
this->nombre = " ";
this->saldo = 0;
}

CuentaBanc::CuentaBanc(int n,string nom, double s){
    numCta = n;
    this->nombre = nom;
    this->saldo = s;

}
void CuentaBanc::setNumCta(double nc){
    numCta = nc;
}

void CuentaBanc::setSaldo(double cant){
    saldo = cant;
}
double CuentaBanc::getNumCta(){
    return numCta;
}

double CuentaBanc::getSaldo(){
    return saldo;
}
void CuentaBanc::deposita(double cant){
    saldo = saldo+cant;
}
bool CuentaBanc::retira(double cant){
    if(saldo-cant>=0){
        saldo = saldo - cant;
        return true;
    }
    else{
        return false;
    }
}
void CuentaBanc::mostrar()
{	cout<<endl;
	cout<<"Tu cuenta "<<numCta<< " tiene un saldo: "<<saldo<<endl;
}

#endif