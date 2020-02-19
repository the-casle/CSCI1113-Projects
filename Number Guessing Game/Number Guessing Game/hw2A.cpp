//
//  main.cpp
//  Number Guessing Game
//
//  Created by Jake Kaslewicz on 2/18/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    int seed;
    int currentGuess;
    cout << "Enter seed:\n";
    cin >> seed;
    
    srand(seed);
    int random = rand() % 9 + 1;
    
    bool win = false;
    
    for(int i = 0; i < 3; i++){
        cout << "What is your guess?\n";
        cin >> currentGuess;
        if(currentGuess == (random + 1) || currentGuess == (random - 1)){
            cout << "Close!\n";
        } else {
            if(currentGuess > random){
                cout << "Too high!\n";
            } else if(currentGuess < random){
                cout << "Too low!\n";
            } else {
                win = true;
                break;
            }
        }
    }
    if(win){
        cout << "Correct!\n";
    } else {
        cout << "You lost, the number was " << random << endl;
    }

    return 0;
}
