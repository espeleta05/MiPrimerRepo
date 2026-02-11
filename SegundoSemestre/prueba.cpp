#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Dame un numero: ";
    cin >> num;
    cout << "Tu numero es: " << num<<endl;
    if (num < 10)
    {
        cout << "Tu numero es menor a 10";
    }
    else
    {
        cout << "Tu numero es mayor a 10";
    }

    return 0;
}