#include <iostream>
using namespace std;

void merge(int izq[], int tamIzq, int der[], int tamDer, int arr[])
{
    int i = 0, j = 0, k = 0;
    while (i < tamIzq && j < tamDer)
    {
        if (izq[i] < der[j])
        {
            arr[k] = izq[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = der[j];
            k++;
            j++;
        }
    }
    while (i < tamIzq)
    {
        arr[k] = izq[i];
        k++;
        i++;
    }
    while (j < tamDer)
    {
        arr[k] = der[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int n)
{
    if (n > 1)
    {
        int tamIzq, tamDer;
        tamIzq = n / 2;
        tamDer = n - tamIzq;
        int izq[tamIzq];
        int der[tamDer];
        for (int i = 0; i < tamIzq; i++)
        {
            izq[i] = arr[i];
        }
        for (int i = 0; i < tamDer; i++)
        {
            der[i] = arr[i + tamIzq];
        }
        mergeSort(izq, tamIzq);
        mergeSort(der, tamDer);
        merge(izq, tamIzq, der, tamDer, arr);
    }
}
int main()
{
    int arr[8] = {6, 1, 7, 3, 2, 8, 0, 9};
    mergeSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}