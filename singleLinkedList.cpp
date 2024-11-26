#include "singleLinkedList.h"
using namespace std;

void singleList::deleteFirstNode() {
    if ( node -> next == NULL ) {
        node = NULL;
        return;
    }
    Node* deleteNode = node;
    node = deleteNode -> next;
    delete deleteNode;
}
void singleList::deleteLastNode() {
    if ( node -> next == NULL ) {
        node = NULL;
        return;
    }
    Node* deleteNode = node -> next;
    Node* prev = node;
    while ( deleteNode -> next != NULL ) {
        prev = prev -> next;
        deleteNode = deleteNode -> next;
    }
    prev -> next = NULL;
    delete deleteNode;
}
void singleList::deleteByValue(string value) {
    Node* deleteNode = node -> next;
    Node* prev = node;
    while ( deleteNode -> key != value ) {
        prev = prev -> next;
        deleteNode = deleteNode -> next;
    }
    prev -> next = deleteNode -> next;
    delete deleteNode;
}
void singleList::addLastElement(string newElement) {
    Node* newNode = new Node{newElement, NULL};
    if ( node == NULL ) {
        node = newNode;
        return;
    }
    Node* last = node;
    while ( last -> next != NULL ) {
        last = last -> next;
    }
    last -> next = newNode;
}
void singleList::addFirstElement(string next) {
    Node* newNode = new Node{next, NULL};
    newNode -> next = node;
    node = newNode;
}
void singleList::printList() {
    while ( node != NULL ) {
        cout << node -> key << " ";
        node = node -> next;
    }
}
bool singleList::findElementNode(string value) {
    Node* newNode = node;
    if ( node == NULL ) {
        return false;
    } 
    while ( newNode -> key != value ) {
        newNode = newNode -> next;
        if ( newNode == NULL ) {
            return false;
        }
    }
    return true;
}
void singleList::changeElementByIndex(string value, int index) {
    Node* newNode = node;
    for ( int i = 0; i < index; i ++ ) {
        newNode = newNode -> next;
    }
    newNode -> key = value;
}
int singleList::sizeOfList() {
    if ( node == NULL ) {
        return 0;
    }
    int size = 0;
    Node* newNode = node;
    while ( newNode != NULL ) {
        size += 1;
        newNode = newNode -> next;
    }
    return size;
}
string singleList::findElementByIndex(int index) {
    if ( index >= sizeOfList() ) {
        return "NULL";
    }
    Node* newNode = node;
    for ( int i = 0; i < index; i ++ ) {
        newNode = newNode -> next;
    }
    return newNode -> key;
}
