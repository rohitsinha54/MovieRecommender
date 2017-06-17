#ifndef NODE_H
#define NODE_H
using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node {
    friend class LinkedList<T>;
public:
    Node(T);
    T getData();
private:
    T data;
    Node* next;
};

template <typename T>
Node<T>::Node(T d) {
    data = d;
    next = 0;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

#endif // NODE_H
