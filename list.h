#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <QJsonObject>



struct Node
{
    QJsonObject data;
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
    void addAtFront(QJsonObject newElement);
     void printList();
    int removeTop();
    int removeBottom();
    int getTop();
    int getBottom();
    int findKey(int keyToFind);
    Node* head;
    int size;
protected:
private:

};


extern LinkedList* list;
#endif // LINKEDLIST_H

