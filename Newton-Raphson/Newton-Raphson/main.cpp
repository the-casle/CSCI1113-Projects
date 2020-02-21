//
//  main.cpp
//  Newton-Raphson
//
//  Created by Jake Kaslewicz on 2/21/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

double rootN(double x, int n);
double powerN(double x, int n);

int main(int argc, const char * argv[]) {
    bool continueRunning = true;
    while(continueRunning){

        double value, root;
        cout << "Enter value and root: ";
        cin >> value;
        cin >> root;
        
        cout << "The root is: " << rootN(value, root) << endl;
        
        
        cout << "Continue? (y/n): ";
        char continueRunningString;
        cin >> continueRunningString;
        if(continueRunningString == 'y'){
            continueRunning = true;
        } else {
            continueRunning = false;
        }
    }
    
    return 0;
}

double rootN(double x, int n){
    double previousGuess = 1;
    double currentGuess = x / 2;
    while(currentGuess >= previousGuess * 1.01 || currentGuess <= previousGuess * .99){
        previousGuess = currentGuess;
        cout << currentGuess <<endl;
        currentGuess = (1/(double)n) * ((n-1) * previousGuess + (x / powerN(previousGuess, (n-1))));
    }
    return currentGuess;
}

double powerN(double x, int n){
    for(int i = 1; i < n; i++){
        x *= x;
        return x;
    }
    return x;
}
