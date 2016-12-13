#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <QJsonObject>
#include <QDateTime>


struct Node
{
    //QJsonObject data;
    Node* next;
    QString comment_id;
    QString link_id;
    QString parent_id;
    QString subreddit;
    QString author;
    QString created_date;
    QString is_edited;
    int ups_number;
    int downs_number;
};

struct Users
{
    Users* next;
    QString user_ID;
    int messagecount=1;
};


class LinkedUsersList
{
public:
    /** Default constructor */
    LinkedUsersList(){
        head = NULL;
        size = 0;
    }
    /** Default destructor */
    virtual ~LinkedUsersList();
    void addAtFront(QString newElement);
     void printList();
    int removeTop();
    int removeBottom();
    int getTop();
    int getBottom();
    int findKey(int keyToFind);
    Users* head;
    int size;
protected:
private:

};

class LinkedList
{
public:
    /** Default constructor */
    LinkedList(){
        head = NULL;
        size = 0;
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
extern LinkedUsersList* userslist;


#endif // LINKEDLIST_H

