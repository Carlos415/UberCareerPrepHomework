//
//  stringPermutation.hpp
//  String Permutation
//
//  Created by Carlos on 5/29/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>


#ifndef stringPermutation_hpp
#define stringPermutation_hpp


using namespace std;

class stringPermutation{
private:
    // There's 26 letters in the alphabet
    static const int tableSize = 26;
    
    // Create node of the item:
    // Contains the letter, counter for occurences,
    // and pointer to next item
    struct item {
        char letter;
        int counter;
        item* next;
    };
    
    item* hashTable[tableSize];
    
public:
    stringPermutation();
    // Converts letter to integer, in order to find a bucket(index).
    int letterToIndex(char letter);
    // Add letter to hashtable
    void addLetterToTable(char letter);
    // Number of occurences a letter has had
    int letterOccurence(char letter);
};



#endif /* stringPermutation_hpp */
