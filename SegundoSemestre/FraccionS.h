#ifndef CascaronFraccions_Fraccions_h
#define CascaronFraccions_FraccionS_h
#include <iostream>
using namespace std;
class FraccionS {
private:
int num, den;
public:
FraccionS();
FraccionS(int n, int d);
int getNum();
int getDen();
void setNum(int n);
void setDen(int d);
FraccionS operator+(FraccionS f);
FraccionS operator*(FraccionS f);
bool operator==(FraccionS f);
bool operator>(FraccionS f);
FraccionS operator++();
FraccionS operator--();
void muestra();
friend double operator!(FraccionS f);
friend FraccionS operator-(FraccionS f1, FraccionS f2);
};
FraccionS::FraccionS() {
num = 1;
den = 2;
}
FraccionS::FraccionS(int n, int d) {
num = n;
den = d;
}
int FraccionS::getNum() {
return num;
}
int FraccionS::getDen() {
return den;
}
void FraccionS::setNum(int n) {
num = n;
}
void FraccionS::setDen(int d) {
den = d;
}
void FraccionS::muestra() {
cout << num << "/" << den << endl;
}
double operator!(FraccionS f) {
return (double)f.num / f.den;
}
FraccionS FraccionS::operator+(FraccionS f) {
FraccionS res;
res.num = num * f.den + den * f.num;
res.den = den * f.den;
return res;
}
FraccionS FraccionS::operator*(FraccionS f) {
FraccionS res;
res.num = num * f.num;
res.den = den * f.den;
return res;
}
bool FraccionS::operator>(FraccionS f) {
return (num * f.den > den * f.num);
}
bool FraccionS::operator==(FraccionS f) {
return (num * f.den == den * f.num);
}
FraccionS FraccionS::operator++() {
FraccionS f;
f.num = num + den;
f.den = den;
return f;
}
FraccionS FraccionS::operator--() {
FraccionS f;
f.num = -num;
f.den = den;
return f;
}
FraccionS operator-(FraccionS f1, FraccionS f2) {
FraccionS f;
f = f1 + --f2;
return f;
}
#endif