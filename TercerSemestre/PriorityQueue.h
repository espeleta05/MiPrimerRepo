//Eugenio Espeleta Alanis 625122
//Adrian Vazquez Ramos 625860
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node* next;
    Node(const T& d, Node* n=nullptr): data(d), next(n) {}
};

template <class T>
class PriorityQueue {
private:
    T* a; 
    int n;
    int cap;    
public:
    PriorityQueue(int c=16): a(new T[c+1]), n(0), cap(c) {}
    PriorityQueue(Node<T>* head, int c=16): a(nullptr), n(0), cap(0) {
        int cnt = 0;
        for (auto p=head; p; p=p->next) ++cnt;
        if (c < cnt) c = cnt;
        a = new T[c+1]; cap = c; n = 0;
        for (auto p=head; p; p=p->next) a[++n] = p->data;
        for (int i = n/2; i >= 1; --i) {
            int k = i;
            while (true) {
                int l = k*2, r = l+1, best = k;
                if (l <= n && a[l] > a[best]) best = l;
                if (r <= n && a[r] > a[best]) best = r;
                if (best == k) break;
                T tmp = a[k]; a[k] = a[best]; a[best] = tmp;
                k = best;
            }
        }
    }
    bool empty() const { return n == 0; }
    const T& top() const { return a[1]; }
    void insert(const T& x) {
        if (n + 1 > cap) {
            int newCap = cap ? cap*2 : 16;
            T* b = new T[newCap+1];
            for (int i=1; i<=n; ++i) b[i] = a[i];
            delete[] a; a = b; cap = newCap;
        }
        a[++n] = x;
        int k = n;
        while (k > 1 && a[k] > a[k/2]) {
            T tmp = a[k]; a[k] = a[k/2]; a[k/2] = tmp;
            k /= 2;
        }
    }
    void remove() {
        if (n == 0) return;
        a[1] = a[n--];
        int k = 1;
        while (true) {
            int l = k*2, r = l+1, best = k;
            if (l <= n && a[l] > a[best]) best = l;
            if (r <= n && a[r] > a[best]) best = r;
            if (best == k) break;
            T tmp = a[k]; a[k] = a[best]; a[best] = tmp;
            k = best;
        }
    }
    void heapSort() {
        for (int i = n/2; i >= 1; --i) {
            int k = i;
            while (true) {
                int l = k*2, r = l+1, best = k;
                if (l <= n && a[l] > a[best]) best = l;
                if (r <= n && a[r] > a[best]) best = r;
                if (best == k) break;
                T tmp = a[k]; a[k] = a[best]; a[best] = tmp;
                k = best;
            }
        }
        int sz = n;
        for (int end = n; end >= 2; --end) {
            T tmp = a[1]; a[1] = a[end]; a[end] = tmp;
            --n;
            int k = 1;
            while (true) {
                int l = k*2, r = l+1, best = k;
                if (l <= n && a[l] > a[best]) best = l;
                if (r <= n && a[r] > a[best]) best = r;
                if (best == k) break;
                T tmp2 = a[k]; a[k] = a[best]; a[best] = tmp2;
                k = best;
            }
        }
        n = sz;
    }
    void print() const {
        for (int i=1; i<=n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
};