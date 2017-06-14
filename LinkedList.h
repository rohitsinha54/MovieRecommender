#include <cstddef>
using namespace std;

template <class T>
class Node {
    private : 
        Node* next;
        T data;
      public:
        Node(T d) {
            data = d;
            next = NULL;
        };
        void setData(T d) {
            data = d;
        };
        T getData() {
            return data;
        };
        void setNext(Node* aNext) { next = aNext; };
        Node* getNext() {
            return next;
        };
};

/*
class Node {
    private :
        Node* next;
        int data;
    public:
        Node( int d) {
            data = d;
            next = NULL;
        };
        void setData(int d) {
            data = d;
        };
        int getData() {
            return data;
        };
        void setNext(Node* aNext) { next = aNext; };
        Node* getNext() {
            return next;
        };
};

*/

template <class T>
class LinkedList {
    private :
        //Node *head;
        Node<T>* head = new Node<T>;
    public :
        LinkedList() {
            head = NULL;
        };
        
        void print() {
            Node<T>* tmp = new Node<T>;
            tmp = head;
            //Node *tmp = head;
            while (tmp->getNext() != NULL) {
                cout << tmp->getData() << endl;
                tmp = tmp->getNext();
            };
        };
        
        void addNode(T d) {
            Node* n = new Node(d);
            Node *t = head;
            if (t != NULL) {
                while (t->getNext() != NULL) {
                    t = t->getNext();
                }
                t->setNext(n);
            } else {
                head = n;
            };
        };
        
        void removeNode(T d) {
            Node *t = head;
            Node *p = NULL;
            if (t != NULL) {
                while (t->getData() != d) {
                    t = t->getNext();
                    p = t;
                }
                if (t->getData() == d) {
                    p->setNext(t->getNext());
                };
            };
        };
        
        Node *getNode(T d) {
            Node *t = head;
            if (t != NULL) {
                while (t->getData() != d) {
                    t = t->getNext();
                }
                if (t->getData() == d) {
                    return t;
                };
            };
        };
};
