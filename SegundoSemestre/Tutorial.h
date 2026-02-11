#include "MateriaDeLectura.h"
#include <iostream>
#include <string>

class TutorialE : public MateriaDeLectura
{
private:
    string url;
    string fecha;

public:
    TutorialE();
    TutorialE(string t, string a, string u, string f);
    void setUrl(string u) { url = u; };
    string getUrl() { return url; };
    void setFecha(string f) { fecha = f; };
    string getFecha() { return fecha; };
    void muestra();
};

TutorialE::TutorialE() : MateriaDeLectura()
{
    url = " ";
    fecha = " ";
}

TutorialE::TutorialE(string t, string a, string u, string f) : MateriaDeLectura(t, a)
{
    url = u;
    fecha = f;
}

void TutorialE::muestra()
{
    cout << "El tutorial  con titulo: " << titulo << " del autor: " << autor << " url:  " << url << " con fehca " << fecha << endl;
}
