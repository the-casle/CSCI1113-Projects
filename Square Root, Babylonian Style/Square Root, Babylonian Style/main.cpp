//
//  main.cpp
//  Square Root, Babylonian Style
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    double initialNumber;
    cout << "Input positive integer to take square root of:\n";
    cin >> initialNumber;
    
    if(initialNumber > 0){
        double previousGuess = 1;
        double currentGuess = initialNumber / 2;
        while(currentGuess >= previousGuess * 1.01 || currentGuess <= previousGuess * .99){
            previousGuess = currentGuess;
            currentGuess = (currentGuess + initialNumber / currentGuess) / 2;
        }
        cout << currentGuess << endl;
    } else {
        cout << "Thats not a positive number\n";
    }
    
    return 0;
}
