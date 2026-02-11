#include <iostream>

using namespace std;

int matricula, udigito;

int main()
{
    /*5/11/29. el grupo de estudiantes*/
    cout<<"Ingrese matricula ";
    cin>>matricula;

    udigito = matricula % 10;
    cout<<"El ultimo digito es "<<udigito;



    return 0;
}
