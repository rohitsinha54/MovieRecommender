#include <iostream>
#include "movierating.h"
#include "node.h"
#include "linkedlist.h"
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

void testMRNode() {
    MovieRating mr = MovieRating(1,4.3);
    Node<MovieRating> n(mr);
    n.getData().printData();
}
*/



int main()
{
    LinkedList<int> il;
    il.insert(5);
    il.print();
    return 0;
}
