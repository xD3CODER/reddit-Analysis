#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
struct dataElement {
  int key;
  int id;
};

struct Node
{
    dataElement data;
    Node* next;
};


class LinkedList
{
public:
    /** Default constructor */
    LinkedList(){
        head = NULL;
        size = 0;// set head to NULL
    }
    /** Default destructor */
    virtual ~LinkedList();
    void addAtFront(int newElement);
    void addAtBack(int newElement);
     void printList();
    int removeTop();
    int removeBottom();
    int getTop();
    int getBottom();
    int findKey(int keyToFind);
protected:
private:
    Node* head;
    int size;
};


/*
class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };

// public member
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
    }

    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
    }

    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        return ret;
    }

// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
};
*/
#endif // LINKEDLIST_H

