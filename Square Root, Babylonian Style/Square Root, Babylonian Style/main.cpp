//
//  main.cpp
//  Square Root, Babylonian Style
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

double babylonianRoot(double initialNumber);

int main(int argc, const char * argv[]) {
    bool continueRoot = true;
    while(continueRoot){
        double initialNumber;
        cout << "Enter a value:\n";
        cin >> initialNumber;
        if(initialNumber > 0){
                cout << "The square root of " << initialNumber << " is " << babylonianRoot(initialNumber) << endl;
                char continueString;
                cout << "continue? (y/n): ";
                cin >> continueString;
                if(continueString == 'y'){
                    continueRoot = true;
                } else {
                    continueRoot = false;
                }
        } else {
            cout << "Thats not a positive number\n";
        }
    }
    return 0;
}

double babylonianRoot(double initialNumber){
    double previousGuess = 1;
    double currentGuess = initialNumber / 2;
    while(currentGuess >= previousGuess * 1.01 || currentGuess <= previousGuess * .99){
        previousGuess = currentGuess;
        currentGuess = (currentGuess + initialNumber / currentGuess) / 2;
    }
    return currentGuess;
}
