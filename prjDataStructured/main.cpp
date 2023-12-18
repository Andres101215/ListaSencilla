#include <iostream>
#include "Dish.h"
#include "LinkedList.cpp"

using namespace std;


int main() {
    LinkedList <char> *linkedList = new LinkedList<char>();

    linkedList->addNoteFirst('A');
    linkedList->addNoteFirst('N');
    linkedList->addNoteFirst('D');
    linkedList->addNoteFirst('R');
    linkedList->addNoteFirst('E');
    linkedList->addNoteFirst('S');

    for(char c: linkedList->getLinkedList()){
     cout<< c;
    }

    delete(linkedList);

    return 0;
}
