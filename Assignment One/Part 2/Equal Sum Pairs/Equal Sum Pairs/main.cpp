//
//  main.cpp
//  Pairs That Equal Sum
//
//  Created by Carlos on 5/27/19.
//  Copyright © 2019 Carlos. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


// This function will print out all of the pairs of the targetSum
template<class T>
void printVector(vector<vector<T>> const &mat) {
    for (vector<T> row: mat) {
        for (T val: row) {
            cout << val << " ";
        }
        cout << '\n';
    }
}


vector<vector<int>> pairsThatEqualSum(vector<int> numbers, int targetSum){
    
    int sumTotal = 0;
    vector<vector<int>> totalSumPairs; // This will hold all the pairs which consists of the targetSum.
    vector<int> sumPairs; // Create a vector containing the set of values which equal to targetSum.
    // Get the size of the array to use in our for-loop. We divide by 4 since our int consists of bytes.
    int vectorSize = numbers.size();
    
    // Sort vector in descending order
    sort(numbers.begin(), numbers.end(), greater<>());
    
    // Test to make sure our array in descending order
    cout << "Our vector contains: ";
    for(int i=0; i<vectorSize; i++){
        cout << numbers[i] << ", ";
    }
    
    cout << endl << endl;
    
    // Create for loop within a for-loop to find all of the values
    // which satisfy our targetSum
    for(int i=0; i<vectorSize; i++){
        // Make sure to clear targetSumValues to start fresh on each iteration.
        // We don't want to carry over the sum from the previous iteration.
        sumPairs.clear();
        sumTotal = 0;
        
        sumTotal = numbers[i];
        
        // Verify our value sumTotal is smaller than the targetSum.
        // If it's smaller, add the following indexes until we reach targetSum.
        // Else iterate to the next index.
        if (targetSum < sumTotal){
            // Make sure to clear sumPairs to start at 0 on each iteration.
            // We don't want to carry over the sum from the previous iteration.
            sumPairs.clear();
        }else if(targetSum == sumTotal){
            sumPairs.push_back(sumTotal);
            totalSumPairs.push_back(sumPairs);
            // Make sure to clear targetSumValues to start fresh on each iteration.
            // We don't want to carry over the sum from the previous iteration.
            sumPairs.clear();
        }else {
            // Add numbers[i] to our vector to keep track of the values that make targetSum
            sumPairs.push_back(numbers[i]);
            for(int j=i+1; j<vectorSize; j++){
                // Add sumTotal and the next index in the numbers[] to find our targetSum
                sumTotal += numbers[j];
                
                // If sumTotal is greater than targetSum subtr
                if(sumTotal > targetSum){
                    sumTotal -= numbers[j];
                } else if(sumTotal < targetSum){
                    sumPairs.push_back(numbers[j]);
                } else if (sumTotal == targetSum){
                    // Add set of numbers that equal targetSum to our totalPairs vector
                    sumPairs.push_back(numbers[j]);
                    totalSumPairs.push_back(sumPairs);
                    sumTotal = sumTotal - numbers[j];
                    sumPairs.pop_back();
                }
            }
        }
    }
    
    printVector(totalSumPairs);
    
    return totalSumPairs;
}




int main() {
    
    vector<int> numbers= {2,4,6,7,8,5,1,3};
    
    pairsThatEqualSum(numbers, 12);
    
    return 0;
}
