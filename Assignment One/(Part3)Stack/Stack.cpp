//
//  Stack.cpp
//  Stacks
//
//  Created by Carlos on 6/3/19.
//  Copyright © 2019 Carlos. All rights reserved.
//
#include <iostream>
#include "Stack.hpp"
using namespace std;


Stack::Stack(){
    vector<int> numStack = {};
    vector<int> minStack = {};
}



// Check if our stack is currently empty
bool Stack::isEmpty(){
    if(numStack.size() == 0)
        return true;
    else
        return false;
}



// Add entry to the top of our stack
bool Stack::push(int entry){
    // begStackSize: hold the size of our stack before we add our entry
    int begStackSize = numStack.size();
    
    // Add entry to the beg of our numStack
    vector<int>::iterator it;
    it = numStack.begin();
    numStack.insert(it, entry);
    
    
    // Add entry to our minStack if it's empty or it's smaller than our top entry
    vector<int>::iterator it1;
    it1 = minStack.begin();
    
    // Add entry to our minStack if it smaller than our current entry.
    if(minStack.size() == 0){
        minStack.insert(it1, entry);
    } else {
        if(minStack[0] >= entry){
            minStack.insert(it1, entry);
        }
    }
    
    
    // Check if our entry was added
    if(begStackSize == numStack.size())
        return false;
    else
        return true;
}



// Pop the top entry
int Stack::pop(){
    // Store the entry before we pop it off our stack
    int valuePopped = numStack[0];
    
    numStack.erase(numStack.begin());
    
    // If valuePopped is our top entry in minStack, then also pop it off minStack
    if(valuePopped == minStack[0]){
        minStack.erase(minStack.begin());
    }
    return valuePopped;
}



// Return the top entry in numStack
int Stack::top(){
    return numStack[0];
}



// Return the min entry from minStack
int Stack::min(){
    return minStack[0];
}



// Print our numStack and minStack
void Stack::printStack(){
    cout << "numStack: ";
    for(int i=0; i<numStack.size(); i++){
        cout << numStack[i] << " ";
    }
    cout << endl;
    
    cout << "minStack: ";
    for(int i=0; i<minStack.size(); i++){
        cout << minStack[i] << " ";
    }
    cout << endl << endl;
    
}


