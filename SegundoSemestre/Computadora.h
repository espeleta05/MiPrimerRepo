#include <iostream>
#include <string>
using namespace std;

class Computadora{
    private:
    string marca;
    string sistOpe;
    int ram;
    public:
    Computadora();
    Computadora(string marcaP, string sistOpeP, int ramP);
    string getMarca(){return marca;};
    string getSistOpe(){return sistOpe;};
    int getRam(){return ram;};
    void setMarca(string marcaP){marca = marcaP;};
    void setSistOpe(string sistOpeP){sistOpe = sistOpeP;};
    void setRam(int ramP){ram = ramP;};

};
Computadora::Computadora(){
    marca = " ";
    sistOpe = " ";
    ram = 0;
}
Computadora::Computadora(string marcaP, string sistOpeP, int ramP){
    marca = marcaP;
    sistOpe = sistOpeP;
    ram = ramP;
}