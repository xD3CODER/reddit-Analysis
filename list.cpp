#include "list.h"
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
 //   tail = 0;
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
       msgBox.setText("Finished");
       msgBox.exec();

}
