#include <iostream>
using namespace std;

int iterativa(int arr[], int n);
int recursiva(int arr[], int n);

int main()
{
    int n = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Suma iterativa: " << iterativa(arr, n) << endl;
    cout << "Suma recursiva: " << recursiva(arr, n-1) << endl; 
    
    return 0;
}

int iterativa(int arr[], int n)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0) 
        {
            cont += arr[i];
        }
    }
    return cont;
}

int recursiva(int arr[], int n) 
{
    if (n < 0) 
        return 0;
    
    if (arr[n] % 2 != 0) 
        return arr[n] + recursiva(arr, n-1);
    else
        return recursiva(arr, n-1);
}