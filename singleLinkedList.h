#ifndef SINGLE_H
#define SINGLE_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
struct Node {
    std::string key;
    Node* next;
};
struct singleList {
    Node* node = NULL;
    void deleteFirstNode();
    void deleteLastNode();
    void deleteByValue(std::string value);
    void addLastElement(std::string newElement);
    void addFirstElement(std::string next);
    void printList();
    bool findElementNode(std::string value);
    std::string findElementByIndex(int index);
    void changeElementByIndex(std::string value, int index);
    int sizeOfList();
};

#endif