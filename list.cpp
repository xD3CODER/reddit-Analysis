#include "list.h"
#include "utils.h"
#include <iostream>
#include <stdlib.h>
#include <QMessageBox>
void delay(int);


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
    temp->created_date = create.fromTime_t(timestamp).toString("dd/MM/yyyy - hh:mm:ss AP");
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
            debug->print_msg("->("+ User->user_ID +" à "+QString::number(User->messagecount)+")");
            User=User->next;
        }
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
