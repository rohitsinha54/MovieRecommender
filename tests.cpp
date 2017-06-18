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
    
    // Test User Rating Array
    mr1.addUserRating(UserRating(1,2.3));
    mr1.addUserRating(UserRating(2,3.3));
    mr1.printUserRatings();
    
    // Test update method
    mr1.updateRating();
    mr1.printData();
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

// Test Linked List Class
void testList() {
    List l;
    l.insertNode(MovieRating(1,4.3));
    l.insertNode(MovieRating(2,3.3));
    Node * n1 = l.getHead();
    n1->getData().printData();
    n1->getNext()->getData().printData();
    
    l.deleteNode(1);
    Node * n2 = l.getHead();
    n2->getData().printData();
}

// Test Node Class With Movie Rating Class
void testMRNode() {
    
    // Test creation
    MovieRating mr1 = MovieRating(1,4.3);
    MovieRating mr2 = MovieRating(2,1.3);
    Node * n1 = new Node(mr1);
    Node * n2 = new Node(mr2);
    n1->getData().printData();
    n2->getData().printData();
    
    // Test setter methods
    n1->setNext(n2);
    cout << (n1->getNext() == n2) << endl;
    
    MovieRating mr3 = MovieRating(3,3.1);
    n1->setData(mr3);
    n1->getData().printData();
}



int main()
{
    testMR();
    return 0;
}
