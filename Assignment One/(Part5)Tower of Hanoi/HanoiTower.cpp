//
//  HanoiTower.cpp
//  Tower of Hanoi
//
//  Created by Carlos on 6/11/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include "HanoiTower.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Create our hash table consisting of the three rods where our rings will go
HanoiTower::HanoiTower(){

    for(int i=0; i<numOfRods; i++){
        rodIndex[i] = {};
    }
}



// Insert the set of numbers(rings) on the first rod
void HanoiTower::insertDiskToStart(int startingRod, vector<int> numbers){
    
    for(int i = 0; i<numbers.size();i++){
        rodIndex[startingRod].push_back(numbers[i]);
    }
}




void HanoiTower::moveDisk(unsigned int startingRod, unsigned int destinationRod){
    
    // get the first value of starting rod and move it to destination rod
    int number = disksAtRod(startingRod)[0];
    // it: the beginning index of the specified rod
    vector<int>::iterator it;
    it = rodIndex[destinationRod].begin();
    // insert value at the beggining of the rod
    rodIndex[destinationRod].insert(it, number);
    
    // erase the value we moved from its initial rod
    rodIndex[startingRod].erase(rodIndex[startingRod].begin());
    
}
//
//
//
vector<int> HanoiTower::disksAtRod(unsigned int rod){
    vector<int> setOfNumbers;
    
    if(rodIndex[rod].size() != 0){
        for(int j = 0; j<rodIndex[rod].size(); j++){
            setOfNumbers.push_back(rodIndex[rod][j]);
        }
    } else
        // if ring is empty return 0
        setOfNumbers.push_back(0);
    
    return setOfNumbers;
}



void HanoiTower::printNumbersOnRod(){
    int i = 0;
   
    // Iterate throuh each rod and print the rings until we reach the last rod
    while(i<numOfRods){
        // If rod has rings, print out their values(number)
        if(rodIndex[i].size() != 0){
            for(int j = 0; j<rodIndex[i].size(); j++){
                cout << rodIndex[i][j];
            }
            cout << "|Ring:" << i << "|\n";
            i++;
        } else{
            cout << "----|Ring:" << i << "|\n";
            i++;
        }
    }
}
