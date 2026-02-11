#include <iostream>
using namespace std;
class Cuadratica{
public:
Cuadratica();
Cuadratica(int, int, int);
void muestra();
Cuadratica operator+(Cuadratica otra);
friend Cuadratica operator-(Cuadratica c1, Cuadratica c2 );
Cuadratica operator*(int val);
friend void operator+=(Cuadratica &c1, Cuadratica &c2);
bool operator==(Cuadratica otra);
friend void operator++(Cuadratica &c1);
private:
int iCoefA, iCoefB, iCoefC;
};
Cuadratica::Cuadratica(){
iCoefA = 1;
iCoefB = 1;
iCoefC = 1;
}
Cuadratica::Cuadratica(int iA, int iB, int iC){
iCoefA = iA;
iCoefB = iB;
iCoefC = iC;
}
void Cuadratica::muestra(){
if (iCoefA != 0){
cout << iCoefA;
cout << "x^2 ";
}
if (iCoefB != 0){
if (iCoefB > 0)
cout << " + ";
cout << iCoefB;
cout << "x ";
}
if (iCoefC != 0){
if (iCoefC > 0)
cout << " + ";
cout << iCoefC << endl;
}
}
Cuadratica Cuadratica::operator+(Cuadratica otra){
Cuadratica nueva;
nueva.iCoefA = iCoefA+otra.iCoefA;
nueva.iCoefB = iCoefB+otra.iCoefB;
nueva.iCoefC = iCoefC+otra.iCoefC;
return nueva;
}
Cuadratica operator-(Cuadratica c1, Cuadratica c2 ){
Cuadratica nueva;
nueva.iCoefA = c1.iCoefA-c2.iCoefA;
nueva.iCoefB = c1.iCoefB-c2.iCoefB;
nueva.iCoefC = c1.iCoefC-c2.iCoefC;
return nueva;
}
Cuadratica Cuadratica::operator*(int val){
Cuadratica nueva;
nueva.iCoefA = iCoefA*val;
nueva.iCoefB = iCoefB*val;
nueva.iCoefC = iCoefC*val;
return nueva;
}
void operator+=(Cuadratica &c1, Cuadratica &c2){
c1.iCoefA = c1.iCoefA+c2.iCoefA;
c1.iCoefB = c1.iCoefB+c2.iCoefB;
c1.iCoefC = c1.iCoefC+c2.iCoefC;
}
bool Cuadratica::operator==(Cuadratica otra){
if(iCoefA == otra.iCoefA && iCoefB == otra.iCoefB && iCoefC==otra.iCoefC){
return true;
} else {
return false;
}
}
void operator++(Cuadratica &c1){
c1.iCoefC=c1.iCoefC+1; //c1.iCoefC++
}