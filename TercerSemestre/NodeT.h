#ifndef NODET_H
#define NODET_H

template <class T> 
class BST;  

template <class T>
class NodeT {
    friend class BST<T>;

private:
    T data;
    NodeT* left;
    NodeT* right;

public:
    NodeT() { data = 0; left = right = nullptr; }
    NodeT(T valor) { data = valor; left = right = nullptr; }
};

#endif
