#ifndef LIST_H
#define LIST_H

class List {
private :
    Node* head;
public :
    List() {
        head = NULL;
    }

    Node* getHead() {
        return head;
    }

    void insert(int ID, double rating) {
        MovieRating mr = MovieRating(ID, rating);
        Node * n1 = new Node(mr);
        Node * c = head;
        if (head != NULL) {
            while (c->getNext() != NULL) {
                c = c->getNext();
            }
            c->setNext(n1);
        } else {
            head = n1;
        }
    }
};

#endif // LIST_H
