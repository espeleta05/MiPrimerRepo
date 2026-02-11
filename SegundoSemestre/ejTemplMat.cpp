#include <iostream>
using namespace std;
template <class  T>
void muestraCol( T mat[10] [10], int size, int col){
for(int r=0;r<size;r++){
    cout<<mat[r][col]<<endl;
}
}
template <class T>
void muestraMatriz(T mat[10][10], int size){
    for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
            cout<<mat[r][c]<<" ";
        }
        cout<<endl;
    }

}
template <class T>
T datoMayor(T mat[10] [10], int size){
    T mayor = mat[0][0];
    for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
            if(mat[r][c]>mayor){
                mayor = mat[r][c];
            }
        }
    }
    return mayor;
}

int main ()
{
    double dMatNum[10][10]  = { {2.5, 3.8, 4.7},

                                {2.2, 4.4, 6.6},

                                {2.5, 3.7, 5.9}};

    string sMatLet[10][10]  = {{"a1", "b2", "c3"},

                            {"dado", "lente", "tren"},

                             {"gato", "iguana", "canario"}};
int iSize = 3;
int iColumna;
double dMayor;
string sMayor;
cout << endl << "Cual columna quieres copiar ";
cin >> iColumna;
cout << "primera matriz "<< endl;
muestraMatriz(dMatNum, iSize);
cout << "Columna de la primera matriz son " << endl;
muestraCol(dMatNum, iSize, iColumna);
cout << "el dato mayor de la matriz es " << endl;
dMayor = datoMayor(dMatNum, iSize);
cout << dMayor << endl;
cout << "segunda matriz "<< endl;
muestraMatriz(sMatLet, iSize);
cout << "Columna de la primera matriz son " << endl;
muestraCol(sMatLet, iSize, iColumna);
cout << "el dato mayor de la matriz es " << endl;
sMayor = datoMayor(sMatLet, iSize);
cout << sMayor << endl;         
return 0;
}