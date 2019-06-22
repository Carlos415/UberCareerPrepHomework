//
//  LinkedList.hpp
//  SinglyLinkedList
//
//  Created by Carlos on 6/3/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

struct Node{
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *head;
    int listSize;
public:
    LinkedList();
    void pushBack(Node *node);
    Node popBack();
    void insert(unsigned int index, Node *node);
    void erase(unsigned int index);
    Node elementAt(unsigned int index);
    void printLinkedList();
    unsigned int size();
    bool palindrome();
};



#endif /* LinkedList_hpp */

