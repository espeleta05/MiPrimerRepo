#include <iostream>
#include <iomanip>
using namespace std;
class Reloj
{
private:
    int hora;
    int minu;

public:
    Reloj();
    Reloj(int h);
    Reloj(int h, int m);
    void setHora(int h);
    void setMin(int m);
    int getHora();
    int getMin();
    void muestra();
    void operator++();
    void operator--();
    Reloj operator+(int m);
    Reloj operator+(Reloj r);
    Reloj operator-(int m);
    Reloj operator-(Reloj r);
    bool operator>(Reloj r);
    bool operator<(Reloj r);
    bool operator==(Reloj r);
};
Reloj::Reloj()
{
    hora = 0;
    minu = 0;
}
Reloj::Reloj(int h)
{
    hora = h;
    minu = 0;
}
Reloj::Reloj(int h, int m)
{
    hora = h;
    minu = m;
}
void Reloj::setHora(int h)
{
    hora = h;
}
void Reloj::setMin(int m)
{
    minu = m;
}
int Reloj::getHora()
{
    return hora;
}
int Reloj::getMin()
{
    return minu;
}
void Reloj::muestra()
{
    if (hora < 10)
        cout << "0";
    cout << hora << ":";
    if (minu < 10)
        cout << "0";
    cout << minu << endl;
}
// incrementa un minuto al reloj
void Reloj::operator++()
{
    minu++;
    if (minu == 60)
    {
        minu = 0;
        hora++;
        if (hora == 24)
        {
            hora = 0;
        }
    }
}
// decrementa un minuto al reloj
void Reloj::operator--()
{
    minu--;
    if (minu < 0)
    {
        minu = 59;
        hora--;
        if (hora < 0)
        {
            hora = 23;
        }
    }
}
// suma un Reloj con una cantidad de minutos y regresa el nuevo Reloj
Reloj Reloj::operator+(int m)
{
    Reloj r;
    int totalMin = minu + m;
    r.hora = hora + (totalMin / 60);
    r.minu = totalMin % 60;
    r.hora = r.hora % 24;
    return r;
}
// suma un Reloj con otro Reloj y regresa un nuevo Reloj
Reloj Reloj::operator+(Reloj r)
{
    Reloj res;
    res.minu = minu + r.minu;
    res.hora = hora + r.hora;
    if (res.minu >= 60)
    {
        res.minu -= 60;
        res.hora += 1;
    }
    res.hora %= 24;
    return res;
}
// a un Reloj le resta una cantidad de minutos y regresa el nuevo Reloj
Reloj Reloj::operator-(Reloj r)
{
    Reloj res;
    int totalMin1 = hora * 60 + minu;
    int totalMin2 = r.hora * 60 + r.minu;
    int resta = totalMin1 - totalMin2;
    if (resta < 0)
        resta += 24 * 60;
    res.hora = resta / 60;
    res.minu = resta % 60;
    return res;
}
// regresa true/false si el primer Reloj es > el segundo
bool Reloj::operator>(Reloj r)
{
    if (hora > r.hora)
    {
        return true;
    }
    else if (hora == r.hora && minu > r.minu)
    {
        return true;
    }
    return false;
}
// regresa true/false si el primer Reloj es < el segundo
bool Reloj::operator<(Reloj r)
{
    if (hora < r.hora)
    {
        return true;
    }
    else if (hora == r.hora && minu < r.minu)
    {
        return true;
    }
    return false;
}
// regresa true/false si ambos relojes son iguales
bool Reloj::operator==(Reloj r)
{
    if (r.hora == hora && r.minu == minu)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Reloj Reloj::operator-(int m)
{
    Reloj res;
    int totalMin = (hora * 60 + minu) - m;
    if (totalMin < 0)
    {
        totalMin += 24 * 60;
    }
    res.hora = totalMin / 60;
    res.minu = totalMin % 60;
    return res;
}