#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
#include "node.h"

template <typename T>
class LinkedList {
public :
    LinkedList();
    ~LinkedList();
    void insert(T);
    void print();
    Node<T>* search(T);
private:
    Node<T> *start;
    Node<T> *end;
    bool isEmpty();
    void insertStart(T);
    void insertEnd(T);
};

template <typename T>
LinkedList<T>::LinkedList() {
    start = NULL;
    end = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    if (!isEmpty()) {
        Node<T> *c = start;
        Node<T> *t;
        while (c != 0) {
            t = c;
            c = c->next;
            delete t;
        }
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    if (start == NULL && end == NULL) {
        return 1;
    } else {
        return 0;
    }
}

template <typename T>
void LinkedList<T>::insertStart(T d) {
    if (isEmpty()) {
        Node<T> * n = new Node<T>(d);
        start = n;
        end = n;
    } else {
        Node<T> * n = new Node<T>(d);
        n->next = start;
        start = n;
    }
}

template <typename T>
void LinkedList<T>::insertEnd(T d) {
    if (isEmpty()) {
        Node<T> * n = new Node<T>(d);
        start = n;
        end = n;
    } else {
        Node<T> * n = new Node<T>(d);
        end->next = n;
        end = n;
    }
}

template <typename T>
void LinkedList<T>::insert(T d) {
    if (isEmpty()) {
        insertStart(d);
    } else {
        if (d < start->data) {
            insertStart(d);
        } else if (d >= end->data) {
            insertEnd(d);
        } else {
            Node<T> * c = start;
            Node<T> * n = new Node<T>(d);
            while (c != end) {
                if ((n->data < c->next->data) && (n->data >= c->data)) {
                    Node<T> * next = c->next;
                    c->next = n;
                    n->next = next;
                    break;
                }
                c = c->next;
            }
        }
    }
}

template <typename T>
void LinkedList<T>::print() {
    if (isEmpty()) {
        cout <<"is empty" << endl;
    } else {
        Node<T> * c = start;
        cout << "Content : ";
        while (c != NULL) {
            cout << c->data << " ";
            c = c->next;
        }
    }
}

template <typename T>
Node<T>* LinkedList<T>::search(T k) {
    Node<T> n;
    bool f = false;
    n = start;
    while ((!f) ** (n != NULL)) {
        if (n->data == k) {
            f = true;
        } else {
            n = n->next;
        }
    }
    return n;
}

#endif // LINKEDLIST_H
