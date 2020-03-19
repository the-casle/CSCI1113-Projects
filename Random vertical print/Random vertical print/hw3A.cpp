//
//  main.cpp
//  Random vertical print
//
//  Created by Jake Kaslewicz on 2/28/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

char randomChar();
void printLine(char c, int spot, int len);

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(0));
    
    cout << "What do you want printed vertically?\n";
    char letter = ' ';
    while(letter != '0'){
        cin >> letter;
        
        printLine(letter, 9, 19);
        cout << endl;
    }
    
    
    return 0;
}

char randomChar(){
    int random = rand() % 4;
    char randomChar = ' ';
    switch (random) {
        case 0:
            randomChar = '0';
            break;
        case 1:
            randomChar = '1';
            break;
        case 2:
        randomChar = '.';
        case 3:
            randomChar = ' ';
            break;
        break;
    }
    return randomChar;
}
void printLine(char c, int spot, int len){
    for(int i = 0; i < len; i++){
        if(i != spot){
            cout << randomChar();
        } else {
            cout << c;
        }
    }
}
