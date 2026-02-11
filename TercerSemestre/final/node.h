template <class T> class LinkedList;
template <class T> class Queue;
template <class T> class Stack;
template <class T>
class Node {
    friend class LinkedList<T>;
    friend class Queue<T>;
    friend class Stack<T>;
private:
    T data;
    Node<T> *next;
public:
    Node(T dato){
        data = dato;
        next= nullptr;
    } 
};