

class Fracciones{
    private:
    int num;
    int den;
    public:
    Fracciones();
    Fracciones(int pNum, int pDen);
    int getNum();
    int getDen();
    void setNum( int pNum);
    void setDen(int pDen);
    double CalcValorReal();
};
Fracciones::Fracciones(){
    num = 1;
    den = 2;
}
Fracciones::Fracciones(int pNum, int pDen){
    num = pNum;
    den = pDen;
}
int Fracciones::getNum(){
    return num;
}
int Fracciones::getDen(){
    return den;
}
void Fracciones::setNum(int pNum){
    num = pNum;
}
void Fracciones::setDen(int pDen){
    den = pDen;
}
double Fracciones::CalcValorReal(){
       return (num * 1.00)/den;
    }