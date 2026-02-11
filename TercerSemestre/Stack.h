#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack(){ size = 0; top = nullptr; }
    int getSize(){ return size;}
    bool isEmpty(){ return top == nullptr ? true : false;}
    void push(T valor);
    T pop();
    T peak();
    void print();
    void clear();
};

template <class T>
void Stack<T>::push(T valor)
{
    Node<T> *ptrNuevo = new Node<T>(valor);
    ptrNuevo->next = top;
    top = ptrNuevo;
    size++;
}

template <class T>
T Stack<T>::pop()
{
    if (!isEmpty())
    {
        T valor = top->data;
        Node<T> *aux = top;
        top = aux->next;
        delete aux;
        size--;
        return valor;
    }
}

template <class T>
T Stack<T>::peak()
{
    if (! isEmpty()) {
        return top->data;
    } else {
        cout<<"Pila vacia";
        return T();
    }
}

template <class T>
void Stack<T>::print()
{
    Node<T> *aux = top;
    if (top != nullptr)
    {
        cout << aux->data << " ";
        while (aux->next != nullptr)
        {
            aux = aux->next;
            cout << aux->data << " ";
        }
    }
}

template <class T>
void Stack<T>::clear()
{
    if (top != nullptr)
    {
        Node<T> *aux = top;
        while (top != nullptr)
        {
            aux = top;
            top = top->next;
            delete aux;
            size--;
        }
    }
}