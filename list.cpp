#include "list.h"
#include <iostream>
#include <stdlib.h>
#include <QMessageBox>



LinkedList::~LinkedList()
{
//dtor
}

void LinkedList::addAtFront(int newElement)
{



    QMessageBox msgBox;
   msgBox.setText("addedtop");
   msgBox.exec();
    Node *temp = new Node();
    temp->data.id = newElement;
    temp->data.key = 0;
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
           result.append("->("+QString::number(temp->data.id)+")");
           temp = temp->next;
           msgBox.setText(result);
           msgBox.exec();
       }

       msgBox.setText("Finished");
       msgBox.exec();

}
