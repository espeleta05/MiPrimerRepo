#ifndef Figura_H
#define Figura_H

class Figura{
    protected:
    int x, y;
    public:
    Figura();
    virtual void dibuja()=0;
};
Figura::Figura(){
    x=1;
    y=1;
}
#endif