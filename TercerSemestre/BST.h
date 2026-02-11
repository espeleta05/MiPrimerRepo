#include <iostream>
#include <queue>
#include "NodeT.h"
using namespace std;

template <class T>
class BST {
private:
    NodeT<T>* root;
    void inorder(NodeT<T>* r);
    void preorden(NodeT<T>* r);
    void posorden(NodeT<T>* r);
    NodeT<T>* sucesor(NodeT<T>* nodo);
    void clear(NodeT<T>* nodo);
    int altura(NodeT<T>* nodo);

public:
    BST() { root = nullptr; }
    bool isEmpty() { return root == nullptr; }
    void insertData(T data);
    bool findData(T data);
    bool deleteData(T data);
    void levelOrder();
    int height();
    void clear();
    void print(int opcion);
};

template <class T>
bool BST<T>::findData(T data) {
    NodeT<T>* aux = root;
    while (aux != nullptr) {
        if (data == aux->data)
            return true;
        else if (data < aux->data)
            aux = aux->left;
        else
            aux = aux->right;
    }
    return false;
}

template <class T>
void BST<T>::insertData(T data) {
    NodeT<T>* nuevo = new NodeT<T>(data);
    if (root == nullptr) {
        root = nuevo;
    } else {
        NodeT<T>* aux = root;
        NodeT<T>* dad = nullptr;
        while (aux != nullptr) {
            dad = aux;
            if (data < aux->data)
                aux = aux->left;
            else
                aux = aux->right;
        }
        if (data < dad->data)
            dad->left = nuevo;
        else
            dad->right = nuevo;
    }
}

template <class T>
bool BST<T>::deleteData(T data) {
    NodeT<T>* aux = root;
    NodeT<T>* parent = nullptr;
    while (aux != nullptr && aux->data != data) {
        parent = aux;
        if (data < aux->data)
            aux = aux->left;
        else
            aux = aux->right;
    }
    if (aux == nullptr)
        return false;
    if (aux->left == nullptr && aux->right == nullptr) {
        if (aux == root)
            root = nullptr;
        else if (parent->left == aux)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete aux;
    } else if (aux->left == nullptr || aux->right == nullptr) {
        NodeT<T>* child = (aux->left != nullptr) ? aux->left : aux->right;
        if (aux == root)
            root = child;
        else if (parent->left == aux)
            parent->left = child;
        else
            parent->right = child;
        delete aux;
    } else {
        NodeT<T>* succ = sucesor(aux);
        T val = succ->data;
        deleteData(succ->data);
        aux->data = val;
    }
    return true;
}

template <class T>
NodeT<T>* BST<T>::sucesor(NodeT<T>* nodo) {
    NodeT<T>* aux = nodo->right;
    while (aux->left != nullptr)
        aux = aux->left;
    return aux;
}

template <class T>
void BST<T>::inorder(NodeT<T>* r) {
    if (r != nullptr) {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

template <class T>
void BST<T>::preorden(NodeT<T>* r) {
    if (r != nullptr) {
        cout << r->data << " ";
        preorden(r->left);
        preorden(r->right);
    }
}

template <class T>
void BST<T>::posorden(NodeT<T>* r) {
    if (r != nullptr) {
        posorden(r->left);
        posorden(r->right);
        cout << r->data << " ";
    }
}

template <class T>
void BST<T>::levelOrder() {
    if (root == nullptr)
        return;
    queue<NodeT<T>*> q;
    q.push(root);
    while (!q.empty()) {
        int nivelSize = q.size();
        for (int i = 0; i < nivelSize; i++) {
            NodeT<T>* aux = q.front();
            q.pop();
            cout << aux->data << " ";
            if (aux->left != nullptr)
                q.push(aux->left);
            if (aux->right != nullptr)
                q.push(aux->right);
        }
        cout << endl;
    }
}

template <class T>
int BST<T>::altura(NodeT<T>* nodo) {
    if (nodo == nullptr)
        return 0;
    int izq = altura(nodo->left);
    int der = altura(nodo->right);
    return 1 + max(izq, der);
}

template <class T>
int BST<T>::height() {
    return altura(root);
}

template <class T>
void BST<T>::clear(NodeT<T>* nodo) {
    if (nodo != nullptr) {
        clear(nodo->left);
        clear(nodo->right);
        delete nodo;
    }
}

template <class T>
void BST<T>::clear() {
    clear(root);
    root = nullptr;
}

template <class T>
void BST<T>::print(int opcion) {
    switch (opcion) {
        case 1:
            cout << "\nPreorden: ";
            preorden(root);
            break;
        case 2:
            cout << "\nInorden: ";
            inorder(root);
            break;
        case 3:
            cout << "\nPosorden: ";
            posorden(root);
            break;
        case 4:
            cout << "\nPor niveles:\n";
            levelOrder();
            break;
        default:
            cout << "\nOpcion invalida";
            break;
    }
    cout << endl;
}
