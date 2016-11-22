#include "list.h"
#include "utils.h"
#include <iostream>
#include <stdlib.h>
#include <QMessageBox>



LinkedList::~LinkedList()
{
//dtor
}

void LinkedList::addAtFront(QJsonObject newElement)
{

    Node *temp = new Node();
    temp->data = newElement;
    temp->next = head;
    head = temp;
    ++size;
}




void LinkedList::printList()
{
      QString result;
      QMessageBox msgBox;
       Node *temp = head;
       while (temp!= NULL) {
           result.append("->("+ temp->data["name"].toString() +")");
           temp = temp->next;
           msgBox.setText(result);
           msgBox.exec();
       }
       debug->msg("Finished");
       msgBox.setText("Finished");
       msgBox.exec();

}
