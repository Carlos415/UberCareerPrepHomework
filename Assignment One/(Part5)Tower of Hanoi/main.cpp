//
//  main.cpp
//  Tower of Hanoi
//
//  Created by Carlos on 6/11/19.
//  Copyright © 2019 Carlos. All rights reserved.
//
#include "HanoiTower.hpp"
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;


int main() {
    
    vector<int> numbers = {1,2,3,4,5};
    int num1;
    int num2;

    
    HanoiTower myHanoiTowers;
    
    myHanoiTowers.insertDiskToStart(0, numbers);
    
    /*
     EVEN # of rings:
     move ring from firstRod to middle rod (or vice versa)
     move ring from first rod to last rod (or vice versa)
     move ring from middle rod and last rod (or vice versa)
     repeat
    */
    if(numbers.size()%2 == 0){
        for(int i = 0; i<numbers.size(); i++){
            // This checks if all of our rings our on the last rod
            while((myHanoiTowers.disksAtRod(2) != numbers)){
                
                // move ring from firstRod to middle rod (or vice versa)
                num1 = myHanoiTowers.disksAtRod(0)[0];
                num2 = myHanoiTowers.disksAtRod(1)[0];
                cout << "Num1: " << num1 << endl;
                cout << "Num2: " << num2 << endl;
                
                if (num1 == 0){
                    myHanoiTowers.moveDisk(1, 0);
                } else if (num2 == 0) {
                    myHanoiTowers.moveDisk(0, 1);
                } else if(num1 < num2){
                    myHanoiTowers.moveDisk(0, 1);
                } else{
                    myHanoiTowers.moveDisk(1, 0);
                }
                myHanoiTowers.printNumbersOnRod();
                cout << endl << endl;
                
                // move ring from first rod to last rod (or vice versa)
                num1 = myHanoiTowers.disksAtRod(0)[0];
                num2 = myHanoiTowers.disksAtRod(2)[0];
                cout << "Num1: " << num1 << endl;
                cout << "Num2: " << num2 << endl;
                
                if (num1 == 0){
                    myHanoiTowers.moveDisk(2, 0);
                } else if (num2 == 0) {
                    myHanoiTowers.moveDisk(0, 2);
                } else if(num1 < num2){
                    myHanoiTowers.moveDisk(0, 2);
                } else{
                    myHanoiTowers.moveDisk(2, 0);
                }
                myHanoiTowers.printNumbersOnRod();
                cout << endl << endl;
                
                
                // move ring from middle rod and last rod (or vice versa)
                num1 = myHanoiTowers.disksAtRod(1)[0];
                num2 = myHanoiTowers.disksAtRod(2)[0];
                cout << "Num1: " << num1 << endl;
                cout << "Num2: " << num2 << endl;
                
                if (num1 == 0){
                    myHanoiTowers.moveDisk(1, 2);
                } else if (num2 == 0) {
                    myHanoiTowers.moveDisk(2, 1);
                } else if(num1 < num2){
                    myHanoiTowers.moveDisk(1, 2);
                } else{
                    myHanoiTowers.moveDisk(2, 1);
                }
                
                myHanoiTowers.printNumbersOnRod();
                cout << endl << endl;
                
            }
        }
        
    }
    
    
    
    
    /*
     ODD # of rings:
     move ring from firstRod to lastRod (or vice versa)
     move ring from first rod to middle rod (or vice versa)
     move ring from middle rod and last rod (or vice versa)
     repeat
     */
    
    if(numbers.size()%2 == 1){
        // This checks if all of our rings our on the last rod
        while((myHanoiTowers.disksAtRod(2) != numbers)){
            // move ring from firstRod to lastRod (or vice versa)
            num1 = myHanoiTowers.disksAtRod(0)[0];
            num2 = myHanoiTowers.disksAtRod(2)[0];
            cout << "Num1: " << num1 << endl;
            cout << "Num2: " << num2 << endl;
            
            if (num1 == 0){
                myHanoiTowers.moveDisk(2, 0);
            } else if (num2 == 0) {
                myHanoiTowers.moveDisk(0, 2);
            } else if(num1 < num2){
                myHanoiTowers.moveDisk(0, 2);
            } else{
                myHanoiTowers.moveDisk(2, 0);
            }
            myHanoiTowers.printNumbersOnRod();
            cout << endl << endl;
            
            
            // move ring from first rod to middle rod (or vice versa)
            num1 = myHanoiTowers.disksAtRod(0)[0];
            num2 = myHanoiTowers.disksAtRod(1)[0];
            cout << "Num1: " << num1 << endl;
            cout << "Num2: " << num2 << endl;
            
            if (num1 == 0){
                myHanoiTowers.moveDisk(1, 0);
            } else if (num2 == 0) {
                myHanoiTowers.moveDisk(0, 1);
            } else if(num1 < num2){
                myHanoiTowers.moveDisk(0, 1);
            } else{
                myHanoiTowers.moveDisk(1, 0);
            }
            myHanoiTowers.printNumbersOnRod();
            cout << endl << endl;
            
            
            // move ring from middle rod and last rod (or vice versa)
            num1 = myHanoiTowers.disksAtRod(1)[0];
            num2 = myHanoiTowers.disksAtRod(2)[0];
            cout << "Num1: " << num1 << endl;
            cout << "Num2: " << num2 << endl;
            
            if (num1 == 0){
                myHanoiTowers.moveDisk(1, 2);
            } else if (num2 == 0) {
                myHanoiTowers.moveDisk(2, 1);
            } else if(num1 < num2){
                myHanoiTowers.moveDisk(1, 2);
            } else{
                myHanoiTowers.moveDisk(2, 1);
            }
            
            myHanoiTowers.printNumbersOnRod();
            cout << endl << endl;
            
        }

       
    }
    return 0;
}
