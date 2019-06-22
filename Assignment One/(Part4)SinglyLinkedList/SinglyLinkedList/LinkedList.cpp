//
//  LinkedList.cpp
//  SinglyLinkedList
//
//  Created by Carlos on 6/3/19.
//  Copyright © 2019 Carlos. All rights reserved.
//
#include <iostream>
#include <vector>
#include "LinkedList.hpp"
using namespace std;


LinkedList::LinkedList(){
    head = NULL;
    listSize = 0;
}


// Adds node to our linked list
void LinkedList::pushBack(Node *node){
    // This will hold our current node
    Node *ptr = head;
    
    // If empty: add node to the list
    // else: add to the end of the list
    if(head == NULL){
        head = node;
        listSize++;
    }
    else {
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
        listSize++;
    }
}


// Remove the last node from the list
Node LinkedList::popBack(){
    // previousNode: holds the previously iterated node.
    // currentNode: holds the current node
    // temp = temporarily holds a node
    Node *previousNode = new Node;
    Node *currentNode = head;
    Node *temp = new Node;
    
    if(currentNode == NULL){
        cout << "Linked List is empty." << endl;
    } else {
        cout << "Linked List not empty." << endl;
        // Check to see if our list only has one or multiple nodes
        if(currentNode->next == NULL){
            cout << "We only have one node in our list\n";
            delete head;
            listSize--;
        } else {
            while(currentNode->next != NULL){
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            
            // Delete the last node, then have prevNode point to NULL
            delete previousNode->next;
            previousNode->next = NULL;

            listSize--;
        }
    }
    return *head;
}



// Insert node at specified index
void LinkedList::insert(unsigned int index, Node *node){

    int counter = 0;
    Node *prevNode = new Node;
    Node *currNode = head;

    // Check to make sure index is within our bounds
    if(index > listSize){
        cout << "Index is out of range!";
    }
    else {
        if(index == 0){
            prevNode = node;
            prevNode->next = head;
            head = prevNode;
            listSize++;
        }
        else {
            while(index != counter){
                prevNode = currNode;
                currNode = currNode->next;
                counter++;
            }
            prevNode->next = node;
            node->next = currNode;
            listSize++;
        }
    }
}



// Erase Node at specified index
void LinkedList::erase(unsigned int index){
    int counter = 0;
    Node *prevNode = new Node;
    Node *currNode = head;

    cout << "List size: " << listSize << endl;
    
    if(index > listSize){
        cout << "Index is out of range.\n";
    } else {
        // If index = 0, remove the first node
        if(index == 0){
            currNode = head->next;
            delete head;
            head = currNode;
            listSize--;
        }
        // Iterate through the list until we find the index of the node
        else {
            while(index != counter){
                prevNode = currNode;
                currNode = currNode->next;
                counter++;
            }
            prevNode->next = currNode->next;
            delete currNode;
            listSize--;
        }
    }
}



// Print our linked list
void  LinkedList::printLinkedList(){
    Node *ptr = head;
    
    cout << "My list: ";
    // Print the values of our nodes as we iterate through our list
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


// Return element at specified index
Node LinkedList::elementAt(unsigned int index){
    int counter = 0;
    Node *indexNode = new Node;
    
    if(index > listSize){
        cout << "Index is out of range.\n";
    }
    else {
        while(index != counter){
            indexNode = head;
            head = head->next;
            counter++;
        }
    }
    return *indexNode;
}



// Return the size of our linked list
unsigned int LinkedList::size(){
    return listSize;
}



// Check to see if our linked list is a palindrome
bool LinkedList::palindrome(){
    
    vector<int> numVector;
    bool palindrome = true;
    
    // Move items in linked list into a vector
    while(head != NULL){
        numVector.push_back(head->data);
        head = head->next;
    }
    
    // while(true && vector not empty)
    while(palindrome && numVector.size() != 0){
        // if vector size == 1: our linked list was odd in size and we popped
        // value off successfully
        if(numVector.size() == 1)
            return true;
        else {
            // Check if the first and last numbers match
            if(numVector[0] == numVector.back()){
                // remove the first and last items if they match
                numVector.erase(numVector.begin());
                numVector.pop_back();
            } else
                palindrome = false;
        }
    }
    return palindrome;
}
