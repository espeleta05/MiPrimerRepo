#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double valor = 0, x;
    int cantCoef;
    cout << "Dame el valor de x ";
    cin >> x;
    cout << "Dame la cantidad de coeficientes ";
    cin >> cantCoef;
    int arr[cantCoef];
    for (int i = 0; i < cantCoef; i++)
    {
        cout << "Dame el coeficiente " << i << " ";
        cin >> arr[i];
    }
    valor += arr[0];
    cout << arr[0];
    for (int i = 1; i < cantCoef; i++)
    {
        cout << " + " << arr[i] << "x^" << i;
        valor += arr[i] * (pow(x, i));
    }
    cout << " = " << valor;
    return 0;
}
