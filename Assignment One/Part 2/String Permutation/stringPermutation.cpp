//
//  stringPermutation.cpp
//  String Permutation
//
//  Created by Carlos on 5/29/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include "stringPermutation.hpp"

using namespace std;
    

stringPermutation::stringPermutation(){
    
    // This will create a hashTable the size of our tableSize
    for(int i=0; i<tableSize; i++){
        hashTable[i] = new item;
        hashTable[i]->letter = '_'; 
        hashTable[i]->counter = 0;
        hashTable[i]->next = NULL;
    }
}


int stringPermutation::letterToIndex(char letter){
    
    int index = 0;
    /*
     I saw that the letter 'a' represent the number 97 when converted to an int, so in
     order to align the letters with the correct index on the hashtable I'm dividing each letter by 97.
     Example: (int)'a' % 97 = 0, (int)'b' % 97 = 1, (int)'c' % 97 = 2, etc
    */
    index = (int)letter % 97;
    
    return index;
}


void stringPermutation::addLetterToTable(char letter){
    // Get the index of the letter
    int index = letterToIndex(letter);
    
    if(hashTable[index]->letter == '_'){
        hashTable[index]->letter = letter;
        hashTable[index]->counter = 1;
    } else {
        item* ptr = hashTable[index];
        item* n = new item;
        n->letter = letter;
        n->counter = 1;
        n->next = NULL;
        
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        
        ptr->next = n;
    }
    
}


int stringPermutation::letterOccurence(char letter){
    
    int occurence = 0;
    int index = (int)letter % 97;
    
    if(hashTable[index]->letter == '_'){
        return occurence;
    } else {
        occurence++;
        // create an item ptr to hashtable index in order to count the number of occurences
        item* ptr = hashTable[index];
        while(ptr->next != NULL){
            occurence++;
            ptr = ptr->next;
        }
    }
    
    cout << "Occurences: " << occurence << endl;
    return occurence;
}
