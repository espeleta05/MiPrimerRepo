#include <iostream>
using namespace std;

#include "Libros.h"
#include "Tutorial.h"

int main()
{
    MateriaDeLectura *material[4];
    char opcion;
    string titulo, autor, editorial, url, fecha;
    int nPags;
    for (int i = 0; i < 4; i++)
    {
        cout << "Quieres un libro <L> o Tutorial <T>?";
        cin >> opcion;
        cout << "Dame el titulo ";
        cin >> titulo;
        cout << "Dame el autor ";
        cin >> autor;
        if (opcion == 'L')
        {
            cout << "Dame editorial ";
            cin >> editorial;
            cout << "Dame el numero de pags ";
            cin >> nPags;
            material[i]=new Libro(titulo, autor, editorial, nPags);
        }
        else
        {
            cout << "Dame url ";
            cin >> url;
            cout << "Dame el fecha ";
            cin >> fecha;
            material[i]=new TutorialE(titulo, autor, url, fecha);
        }
    }
    cout << "La bibliografía utilizada para realizar la investigación es: \n";
    for (int i = 0; i < 4; i++)
    {
        material[i]->muestra();
    }
    return 0;
}