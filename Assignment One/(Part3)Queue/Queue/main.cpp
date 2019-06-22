//
//  main.m
//  Queue
//
//  Created by Carlos on 6/19/19.
//  Copyright © 2019 Carlos. All rights reserved.
//
#include "Queue.hpp"
#include <iostream>


using namespace std;

int main() {

    Queue myQueue;
    
    // Add values to our queue
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    
    myQueue.printQueue();
    
    // Pop a value
    myQueue.dequeue();
    myQueue.dequeue();
    // Test to make sure nothing happens if we pop to many entries
//    myQueue.dequeue();
//    myQueue.dequeue();
//    myQueue.dequeue();
    
    myQueue.printQueue();
    
    return 0;
}
