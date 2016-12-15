#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <QJsonObject>
#include <QDateTime>


struct Node
{
    Node* next;
    QString comment_id;
    QString link_id;
    QString parent_id;
    QString subreddit;
    QString author;
    QDateTime created_date;
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
    Users* head;
    int size;
    Users *getUsersPosts(Node *data);

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
    Node* head;
    int size;
    long int countNewThreads(Node* liste);
    QVector< QVector< int > > getCommentDateStats(Node* list);
protected:
private:

};


extern LinkedList* list;
extern LinkedUsersList* userslist;


#endif // LINKEDLIST_H

