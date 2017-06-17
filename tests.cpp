#include <iostream>
#include "movierating.h"
#include "node.h"
#include "list.h"
using namespace std;

// Test MovieRating Class
void testMR() {
    MovieRating mr1 = MovieRating(1,4.3);
    MovieRating mr2 = MovieRating(2,3.5);
    mr2.setID(3);
    mr2.setRating(2.4);
    mr1.printData();
    mr2.printData();
}

/*
// Test Node Class with int type
template <class T>
void testIntNode() {
    Node<T>* n;
    n->data = 5;
    cout << n->data << endl;
}

*/
void testList() {
    List l;
    l.insert(1,4.3);
    l.insert(2,2.3);
    Node * n1 = l.getHead();
    n1->getData().printData();
    n1->getNext()->getData().printData();
}

// Test Node Class With Movie Rating Class
void testMRNode() {
    MovieRating mr1 = MovieRating(1,4.3);
    MovieRating mr2 = MovieRating(2,1.3);
    Node * n1 = new Node(mr1);
    Node * n2 = new Node(mr2);
    n1->getData().printData();
    n2->getData().printData();
    n1->setNext(n2);
    cout << (n1->getNext() == n2) << endl;
}



int main()
{
    testList();
    return 0;
}
