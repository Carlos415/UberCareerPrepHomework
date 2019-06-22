//
//  Queue.cpp
//  Queue
//
//  Created by Carlos on 6/19/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include "Queue.hpp"
#include <vector>
#include <iostream>

using namespace std;

Queue::Queue(){
    vector<int> queueList = {};
}



// Add entry to our queue
void Queue::enqueue(int entry){
    // insert value at the beginning of our list
    vector<int>::iterator it;
    it = queueList.begin();
    it = queueList.insert (it , entry);

}



// Pop the last entry from our queueList
void Queue::dequeue(){
    // Before we pop the last value on our list, make sure
    // it's not empty
    if(queueList.size() == 0)
        cout << "Queue is empty.\n";
    else
        queueList.pop_back();
}



// Print first in, first out order
void Queue::printQueue(){
    
    cout << "Queue List: ";
    
    for(int i=0; i<queueList.size(); i++){
        cout << queueList[i] << ",";
    }
    cout << endl;
}
