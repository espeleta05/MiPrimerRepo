#include <iostream>
#include "CuentaBanc.h"
using namespace std;
class Chequera : public CuentaBanc {
private:
double comision;
public:
void setComision(double c) { comision = c; }
double getComision() { return comision; }
Chequera();
Chequera(int n, double s, double c);
void mostrar();
bool retira(double cant);
};
Chequera::Chequera() : CuentaBanc() {
comision = 0;
}
Chequera::Chequera(int n, double s, double c) : CuentaBanc(n, s) {
comision = c;
}
void Chequera::mostrar() {
cout << endl;
cout << "Tu cuenta " << numCta << " tiene un saldo: " << saldo << endl;
}
bool Chequera::retira(double cant) {
if (saldo >= cant + comision) {
saldo -= (cant + comision);
cout << "Retiro exitoso. Comisión aplicada: " << comision << endl;
return true;
} else {
cout << "La operación no es posible: saldo insuficiente para el retiro y la comisión." << endl;
return false;
}
}