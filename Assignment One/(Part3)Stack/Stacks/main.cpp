//
//  main.cpp
//  Stacks
//
//  Created by Carlos on 6/3/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
using namespace std;


int main() {
    
    Stack myStack;
    
    // Test to see if we added entry to stack
    myStack.push(34);
    myStack.push(13);
    myStack.push(433);
    myStack.push(3);
    myStack.push(55);
    
    myStack.printStack();
    
    cout << "Value popped: " << myStack.pop() << endl;

    myStack.printStack();

    cout << "Top value: " << myStack.top() << endl;
    cout << "Min value: " << myStack.min() << endl;
    cout << endl;
    
    cout << "Value popped: " << myStack.pop() << endl;
    
    myStack.printStack();

    cout << "Top value: " << myStack.top() << endl;
    cout << "Min value: " << myStack.min() << endl;


    
    
    return 0;
}
