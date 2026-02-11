#include <iostream>
#include "Complejo.h"
using namespace std;
int main(){
Complejo cA, cF, cG;
double real, ima;
cout<<"Dame el valor real del complejo 2: ";
cin>>real;
cout<< "Dame el valor imaginario del complejo 2: ";
cin>>ima;
Complejo cB(real,ima);
cout<<"Dame el valor real del complejo 3: ";
cin>>real;
cout<< "Dame el valor imaginario del complejo 3: ";
cin>>ima;
Complejo cC(real,ima);
Complejo cD;
cD = cB.suma(cC);
Complejo cE;
cE = cB.resta(cC);
cF = cB+cC;
cG = cB*cC;
if (cB == cC){
cout<<" cB y cC Son iguales\n";
} else {
cout<<"cB y cC Son diferentes\n";
}
cout<<"\nComplejo A: ("<<cA.getReal()<<","<<cA.getIma()<<")\n"<<endl;
cout<<"Complejo B: ("<<cB.getReal()<<","<<cB.getIma()<<")\n"<<endl;
cout<<"Complejo C: ("<<cC.getReal()<<","<<cC.getIma()<<")\n"<<endl;
cout<<"Complejo D: ("<<cD.getReal()<<","<<cD.getIma()<<")\n"<<endl;
cout<<"Complejo E: ("<<cE.getReal()<<","<<cE.getIma()<<")\n"<<endl;
cout<<"Complejo F sumna de b+c ("<<cF.getReal()<<","<<cF.getIma()<<")\n"<<endl;
cout<<"Complejo G multiplicacion b*c ("<<cG.getReal()<<","<<cG.getIma()<<")\
n"<<endl;
return 0;
}