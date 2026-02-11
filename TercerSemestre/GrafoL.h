#include <iostream>
using namespace std;

template <class T> class GrafoL;

template <class T>
class NodeL {
    friend class GrafoL<T>;
private:
    T data;
    NodeL<T>* nextAdj;   
    NodeL<T>* nextNode;  
public:
    NodeL(const T& v) : data(v), nextAdj(nullptr), nextNode(nullptr) {}
};

template <class T>
class GrafoL {
private:
    NodeL<T>* head;  
    int sizeNode;

    NodeL<T>* findVertex(const T& v) const {
        NodeL<T>* cur = head;
        while (cur != nullptr) {
            if (cur->data == v) return cur;
            cur = cur->nextNode;
        }
        return nullptr;
    }
 
   
    void appendAdj(NodeL<T>* v, const T& to) {
       
        NodeL<T>* walk = v->nextAdj;
        while (walk != nullptr) {
            if (walk->data == to) return; 
            walk = walk->nextAdj;
        }

        NodeL<T>* n = new NodeL<T>(to);
        if (v->nextAdj == nullptr) {
            v->nextAdj = n;
        } else {
            NodeL<T>* tail = v->nextAdj;
            while (tail->nextAdj != nullptr) tail = tail->nextAdj;
            tail->nextAdj = n;
        }
    }

public:
    GrafoL() : head(nullptr), sizeNode(0) {}

    void addVertex(const T& data) {
        if (findVertex(data) != nullptr) return; 
        NodeL<T>* ptr = new NodeL<T>(data);
        if (head == nullptr) {
            head = ptr;
        } else {
            NodeL<T>* aux = head;
            while (aux->nextNode != nullptr) aux = aux->nextNode;
            aux->nextNode = ptr;                 
        }
        sizeNode++;
    }

    
    void addEdge(const T& from, const T& to) {
        NodeL<T>* u = findVertex(from);
        NodeL<T>* v = findVertex(to);
        if (u == nullptr || v == nullptr) return; 

        appendAdj(u, to);
        appendAdj(v, from);
    }

    void print() const {
        NodeL<T>* v = head;
        while (v != nullptr) {
            cout << v->data << " : ";
            NodeL<T>* a = v->nextAdj;
            while (a != nullptr) {
                cout << a->data;
                if (a->nextAdj != nullptr) cout << " -> ";
                a = a->nextAdj;
            }
            cout << '\n';
            v = v->nextNode;
        }
    }
};