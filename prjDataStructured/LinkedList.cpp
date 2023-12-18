//
// Created by andre on 15/11/2023.
//

#include "LinkedList.h"
#include <vector>
#include <string>
template<class T>
LinkedList<T>::LinkedList() {
  LinkedList::head==NULL;
}


template<class T>
bool LinkedList<T>::isEmpty() {
    return head== NULL;
}

template<class T>
void LinkedList<T>::addNoteFirst(T info) {
  if(isEmpty()){
    head=new Node<T>(info);
  }else{
      Node<T> *aux=head;
      while(aux-> next != NULL){
          aux=aux->next;
      }
      Node<T> *node=new Node<T>(info);
      aux->next=node;
  }
}

template<class T>
void LinkedList<T>::addNodeSorted(T info) {
    Node<T> *newNode = new Node<T>(info);

    if (head == NULL || info < head->info) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node<T> *current = head;
    while (current->next != NULL && info >= current->next->info) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

template<class T>
void LinkedList<T>::addNodeBeforeTo(Node<T> *node, T info) {
    Node<T> *newNode = new Node<T>(info);
    if (node == head) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node<T> *current = head;
    while (current->next != NULL) {
        if (current->next == node) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::addNodeAfterTo(Node<T> *node, T info) {
    Node<T> *newNode = new Node<T>(info);

    if (node == head) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node<T> *current = head;
    while (current != NULL && current->next != node) {
        current = current->next;
    }
    if (current == NULL) {
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

template<class T>
void LinkedList<T>::addNodeLast(T info) {
    Node<T> *newNode = new Node<T>(info);
    Node<T> *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
        current->next=newNode;
        newNode->next=NULL;
}


template<class T>
std::vector<T> LinkedList<T>::getLinkedList() {
    std::vector<T> linked;
    Node<T> *aux= head;
    while(aux!=NULL){
        linked.push_back((aux -> info));

        aux = aux-> next;
    }
    return linked;
}


template<class T>
Node<T> LinkedList<T>::findNode(std::string id) {
    Node<T> *current = head;
    while (current != NULL) {
        if (current->info.getId() == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


template<class T>
T LinkedList<T>::getLast() {
    Node<T> *aux=head;
    while(aux != NULL){
        return aux;
    }
    return NULL;
}

template<class T>
T LinkedList<T>::getFirst() {
    if(head==NULL){
        return NULL;
    }
    return head->info;
}

template<class T>
T* LinkedList<T>::getObject(int aux) {
    if (aux < 0 || aux >= getSize()) {
        return NULL;
    }

    Node<T> *current = head;
    for (int i = 0; i < aux; ++i) {
        current = current->next;
    }
    return &(current->info);
}

template<class T>
int LinkedList<T>::getSize() {
    Node<T> *current = head;
    int con=0;
    while (current != NULL) {
       con++;
    }
    return con;
}

template<class T>
T LinkedList<T>::deleteNode(Node<T> *node) {
    if (node == head) {
        head = node->next;
        T info = node->info;
        delete node;
        return info;
    }

    Node<T> *current = head;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == NULL) {
        return T();
    }

    current->next = node->next;
    T info = node->info;
    delete node;
    return info;
}

template<class T>
T* LinkedList<T>::findinfo(std::string id) {
    Node<T> *current = head;
    while (current != NULL) {
        if (current->info.getId() == id) {
            return &(current->info);
        }
        current = current->next;
    }
    return NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    while (head != NULL) {
        Node<T> *delaux = head;
        head = head->next;
        delete (delaux);
    }
    delete(head);
}