//
//  main.cpp
//  String Permutation
//
//  Created by Carlos on 5/29/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

#include "stringPermutation.hpp"

// This function will check if the letters in shortWord are present in longWord
bool matchStringLetters(string shortWord, string longWord){
    // indexNotFound: when a letter or index is not found in our string, it
    // returns this value. We will use this in our if statement to make it easier to read.
    int indexNotFound = 18446744073709551615;
    
    // Iterate through shortWord to check if the letters can be found in both words
    for(int i=0; i<shortWord.length(); i++){
        char letter = (char)shortWord[i];
        if(shortWord.find(letter) == indexNotFound && longWord.find(letter) == indexNotFound){
            return false;
        }
    }
    return true;
}


bool isStringPermutation(string s1, string s2){
    
    stringPermutation string1;
    stringPermutation string2;
    char letter1, letter2;
    bool matchResult;
    
    // Add each letter in s1 to string1 hashtable
    for(int i=0; i<s1.length(); i++){
        letter1 = (char)s1[i];
        string1.addLetterToTable(letter1);
    }
    
    cout << endl;
    
    // Add each letter in s2 to string2 hashtable
    for(int i=0; i<s2.length();i++){
        letter2 = (char)s2[i];
        string2.addLetterToTable(letter2);
    }
    
    // Find the shortest string, so we can check if it fits inside
    // the longer string to reduce the amount of comparisons
    // Ex: "mississippi" vs "mips"
    if(s1.length() > s2.length()){
        for(int i=0; i<s2.length(); i++){
            letter2 = (char)s2[i];

            // matchResult: checks to see if the letters in s2 can be found in s1 before
            // we compare the occurences of each letter
            matchResult = matchStringLetters(s2, s1);
            
            if(matchResult){
                // Check to see if letter occurences for s2 are less than s1
                if(string1.letterOccurence(letter2) < string2.letterOccurence(letter2)){
                    return false;
                }
            }
        }
    }else {
        for(int i=0; i<s1.length(); i++){
            letter1 = (char)s1[i];

            // matchResult: checks to see if the letters in s1 can be found in s2 before
            // we compare the occurences of each letter
            matchResult = matchStringLetters(s1, s2);
            
            if(matchResult){
                // Check to see if letter occurences for s1 are less than s2
                if(string1.letterOccurence(letter1) > string2.letterOccurence(letter1)){
                    return false;
                }
            }
        }
    }
    return true;
}


int main() {

    string word1, word2;
    
    cout << "Enter first word: ";
    cin >> word1;
    
    cout << "Enter second word: ";
    cin >> word2;
    
    bool Result = isStringPermutation(word1, word2);
    
    if(Result)
        cout << "Permutation found!";
    else
        cout << "No permutation found";
    
    
    return 0;
}
