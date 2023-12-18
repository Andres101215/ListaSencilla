//
// Created by andre on 15/11/2023.
//

#ifndef PRJDATASTRUCTURED_LINKEDLIST_H
#define PRJDATASTRUCTURED_LINKEDLIST_H
#include "Node.h"
#include <vector>
#include <string>

template <class T>

class LinkedList {
public:
    LinkedList();

    bool isEmpty();

    void addNoteFirst(T info);

    void addNodeLast(T info);

    void addNodeAfterTo(Node<T>* node,T info);

    void addNodeBeforeTo(Node<T>* node,T info);

    void addNodeSorted(T info);


    T* findinfo(std::string id);

    T deleteNode (Node<T>* node );

    int getSize();

    T* getObject(int pos);

    T getFirst();

    T getLast();

    std::vector<T> getLinkedList();

    virtual ~LinkedList();

    Node<T> findNode(std::string id);

private:
    Node<T> *head;
};



#endif //PRJDATASTRUCTURED_LINKEDLIST_H
