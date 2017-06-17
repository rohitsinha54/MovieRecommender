#ifndef NODE_H
#define NODE_H

#include "movierating.h"
using namespace std;

class Node {
private:
    Node* next;
    MovieRating data;
public :
    Node(MovieRating d) : data(0,0.0) {
        data = d;
        next = NULL;
    }
    
    void setData(MovieRating d) {
        data = d;
    }

    MovieRating getData() {
        return data;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }
};


#endif // NODE_H
