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

    void insertNode(MovieRating mr) {
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
    
    void deleteNode(int ID) {
        Node * c = head;
        Node * p = head;
        if (head->getData().getID() == ID) {
            head = head->getNext();
        } else if (head != NULL) {
            while (c->getNext() != NULL && c->getData().getID() != ID) {
                p = c;
                c = c->getNext();
            }
            if (c->getData().getID() == ID) {
                p->setNext(c->getNext());
            }
        }
    }
    
    Node* getNode(int ID) {
        Node * c = head;
        if (head != NULL) {
            while (c->getNext() != NULL && c->getData().getID() != ID) {
                c = c->getNext();
            }
            if (c->getData().getID() == ID) {
                return c;
            }
        } else {
            return NULL;
        }
    }
};

#endif // LIST_H
