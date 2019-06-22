//
//  Stack.hpp
//  Stacks
//
//  Created by Carlos on 6/3/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include<vector>

using namespace std;

//struct Node{
//    int data;
//    Node *next;
//};


class Stack{
private:
    // Keeps track of the lowest element
    vector<int> numStack;
    vector<int> minStack;
    
    int lowestElement;
public:
    Stack();
    bool isEmpty();
    bool push(int entry);
    int pop();
    int top();
    int min();
    void printStack();
};


#endif /* Stack_hpp */
