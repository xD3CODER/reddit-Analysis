#include "list.h"
#include "utils.h"
#include <iostream>
#include <stdlib.h>
#include <QMessageBox>


LinkedList::~LinkedList()
{

}
LinkedUsersList::~LinkedUsersList()
{

}

void LinkedList::addAtFront(QJsonObject data)
{

    Node *temp = new Node();
    temp->author = data["author"].toString();
    temp->comment_id = data["name"].toString();
    temp->link_id = data["link_id"].toString();
    temp->parent_id = data["parent_id"].toString();
    quint32 timestamp = data["created_utc"].toString().toUInt();
    QDateTime create;
    temp->created_date = create.fromTime_t(timestamp);
    temp->is_edited = data["edited"].toString();
    temp->downs_number = data["downs"].toString().toInt();
    temp->ups_number = (int)data["ups"].toInt();
    temp->subreddit = data["subreddit"].toString();
    temp->next = head;
    head = temp;
    ++size;
}


void LinkedUsersList::addAtFront(QString username)
{
    Users *temp = new Users();
    temp->user_ID = username;

    temp->next = head;
    head = temp;
    ++size;
}

void LinkedUsersList::printList()
{
    Users *User = userslist->head;

        while(User != NULL)
        {
            debug->print_msg( User->user_ID +" à posté "+QString::number(User->messagecount) +" messages");
            User=User->next;
        }
}


void LinkedList::getUsers()
{

}


void LinkedList::printList()
{
       QString result;
       QMessageBox msgBox;
       Node *temp = head;
       while (temp->next != NULL) {
           result.append("->("+ temp->comment_id +")");
           temp = temp->next;
           msgBox.setText(result);
           msgBox.exec();
       }
       debug->print_msg("Finished");
       msgBox.setText("Finished");
       msgBox.exec();

}

long int LinkedList::countNewThreads(Node *message) {
     long int count = 0;

    while(message != NULL) {

        if(message->parent_id == message->link_id) {
            count++;
        }
        message = message->next;
    }

    return count;
}

QVector< QVector< int > > LinkedList::getCommentDateStats(Node *message) {
    QVector< QVector< int > > count(2);
    count[0].resize(25);
    count[1].resize(32);

    while(message != NULL) {
        count[1][message->created_date.date().day()]++;
        count[0][message->created_date.time().hour()]++;
        message = message->next;
    }


    return count;
}

Users *LinkedUsersList::getUsersPosts(Node *data) {
    int count = 0;
    Users *User = userslist->head;

    while(data != NULL)
    {
        while(User != NULL)
        {
            if(User->user_ID == data->author)
            {
                User->messagecount = User->messagecount+1;
                count++;
            }
             User=User->next;
        }
        if(count == 0)
        {
            userslist->addAtFront(data->author);
        }
        User = userslist->head;
        count = 0;
        data = data->next;
    }
     debug->print_msg("Finished");
     return userslist->head;
}
