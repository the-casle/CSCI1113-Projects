//
//  main.cpp
//  Dice Game
//
//  Created by Jake Kaslewicz on 3/20/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int fancyRolling();
int basicRoll();

int main(int argc, const char * argv[]) {
    srand((int)time(0));
    
    double numberRolls;
    cout << "How many times?\n";
    cin >> numberRolls;
    
    int rolls[20];
    
    for(int i = 0; i < 20; i++){
        rolls[i] = 0;
    }
    
    for(int i = 0; i < numberRolls; i++){
        int roll = fancyRolling();
        rolls[roll] ++;
    }
    
    for(int i = 1; i < 20; i++){
        if(rolls[i] != 0){
            double percent = (rolls[i] / numberRolls) * 100;
            cout << "Roll " << i << ": " << fixed << percent << "%" << endl;
        }
    }
    
    return 0;
}

int fancyRolling(){
    int roll = basicRoll();
    int j = 0;
    while (roll == 12) {
        roll = basicRoll();
        j++;
    }
    return roll + j;
}
int basicRoll(){
    int random1 = rand() % 6 + 1;
    int random2 = rand() % 6 + 1;
    return random1 + random2;
}
