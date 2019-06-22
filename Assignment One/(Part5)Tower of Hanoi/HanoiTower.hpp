//
//  HanoiTower.hpp
//  Tower of Hanoi
//
//  Created by Carlos on 6/11/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#ifndef HanoiTower_hpp
#define HanoiTower_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class HanoiTower{
private:
    static const int numOfRods = 3;
    vector<int> rodIndex[numOfRods];

    
public:
    HanoiTower();
    void insertDiskToStart(int startingRod, vector<int> numbers);
    void moveDisk(unsigned int startingRod, unsigned int destinationRod);
    vector<int> disksAtRod(unsigned int rod);
    unsigned int numberOfRods();
    void printNumbersOnRod();
};


#endif /* HanoiTower_hpp */
