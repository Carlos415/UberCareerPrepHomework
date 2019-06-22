//
//  Queue.hpp
//  Queue
//
//  Created by Carlos on 6/19/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Queue{
   
public:
    vector<int> queueList;
    
    Queue();
    void enqueue(int entry);
    void dequeue();
    void printQueue();
};

#endif /* Queue_hpp */
