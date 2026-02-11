#include <iostream>
using namespace std;
#include "Reloj.h"

int main()
{
    int a1, a2, b2, a3, b3, op;
    cin >> op;
    cin >> a1 >> a2 >> b2 >> a3 >> b3;
    Reloj r1(a1), r2(a2, b2), r3(a3, b3), r4, r5, r6;
    switch (op)
    {
    case 1:
    {
        ++r1;
        ++r2;
        ++r3;
        r1.muestra();
        r2.muestra();
        r3.muestra();
        break;
    }
    case 2:
    {
        --r1;
        --r2;
        --r3;
        r1.muestra();
        r2.muestra();
        r3.muestra();
        break;
    }
    case 3:
    {
        r4 = r1 + r2;
        r5 = r1 + r3;
        r6 = r2 + r3;
        r4.muestra();
        r5.muestra();
        r6.muestra();
        break;
    }
    case 4:
    {
        r4 = r1 + 20;
        r5 = r2 + 60;
        r6 = r3 + 100;
        r4.muestra();
        r5.muestra();
        r6.muestra();
        break;
    }
    case 5:
    {
        r4 = r1 - r2;
        r5 = r1 - r3;
        r6 = r2 - r3;
        r4.muestra();
        r5.muestra();
        r6.muestra();
        break;
    }
    case 6:
    {
        r4 = r1 - 20;
        r5 = r2 - 60;
        r6 = r3 - 100;
        r4.muestra();
        r5.muestra();
        r6.muestra();
        break;
    }
    case 7:
    {
        if (r1 > r2)
            cout << "r1 SI es mayor a r2" << endl;
        else
            cout << "r1 NO es mayor a r2" << endl;
        if (r1 > r3)
            cout << "r1 SI es mayor a r3" << endl;
        else
            cout << "r1 NO es mayor a r3" << endl;
        if (r2 > r3)
            cout << "r2 SI es mayor a r3" << endl;
        else
            cout << "r2 NO es mayor a r3" << endl;
        break;
    }
    case 8:
    {
        if (r1 < r2)
            cout << "r1 SI es menor a r2" << endl;
        else
            cout << "r1 NO es menor a r2" << endl;
        if (r1 < r3)
            cout << "r1 SI es menor a r3" << endl;
        else
            cout << "r1 NO es mayor a r3" << endl;
        if (r2 < r3)
            cout << "r2 SI es menor a r3" << endl;
        else
            cout << "r2 NO es menor a r3" << endl;
        break;
    }
    case 9:
    {
        if (r1 == r2)
            cout << "r1 SI es igual a r2" << endl;
        else
            cout << "r1 NO es igual a r2" << endl;
        if (r1 == r3)
            cout << "r1 SI es igual a r3" << endl;
        else
            cout << "r1 NO es igual a r3" << endl;
        if (r2 == r3)
            cout << "r2 SI es igual a r3" << endl;
        else
            cout << "r2 NO es igual a r3" << endl;
        break;
    }
    }
}