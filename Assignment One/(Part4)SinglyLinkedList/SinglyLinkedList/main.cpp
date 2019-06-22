//
//  main.cpp
//  SinglyLinkedList
//
//  Created by Carlos on 6/3/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
    
    LinkedList myList;
    
    Node *newNode = new Node;
    
    newNode->data = 0;
    newNode->next = NULL;
    myList.pushBack(newNode);
    
    // *** Why do I have to use a different variable name to push a new node?? ***
    Node *newer = new Node;
    newer->data = 1;
    newer->next = NULL;
    myList.pushBack(newer);

    Node *n = new Node;
    n->data = 1;
    n->next = NULL;
    myList.pushBack(n);
    
    Node *ne = new Node;
    ne->data = 0;
    ne->next = NULL;
    myList.pushBack(ne);
    
    // Test node for insert
//    Node *test = new Node;
//    test->data = 44;
//    test->next = NULL;
    
    
    
    cout << "Size counter: " << myList.size() << endl;
    
    //myList.printLinkedList();
    
    //myList.insert(1, test);
    
    //myList.printLinkedList();
    
    //myList.erase(2);

    //myList.printLinkedList();
    
    //myList.popBack();

    myList.printLinkedList();
    
    cout << endl;
    
//    Node *newone = new Node;
//    newone->data = 0;
//    newone->next = NULL;
//
//    cout << "Before: \n";
//    cout << "newone data: " << newone->data << endl;
//    cout << "newone next: " << newone->next << endl;
//
//    *newone = myList.elementAt(2);
//
//    cout << "After: \n";
//    cout << "newone data: " << newone->data << endl;
//    cout << "newone next: " << newone->next->data << endl;
//
    // Test palindrome
    if(myList.palindrome())
        cout << "Palindrome!\n";
    else
        cout << "Not Palindrome\n";
    
    
    
    return 0;
}
