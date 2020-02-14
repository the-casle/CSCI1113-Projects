//
//  main.cpp
//  Roman Numeral Conversion
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

bool between(double lower, double upper, double value){
    if(value >= lower && value <= upper) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    double input;
    
    cout << "Enter an integer value from 1 to 999: ";
    cin >> input;
    
    double remaining = input;
    
    if(input <= 999 && input >= 1){
        while(remaining > 0){
            if(between(900, 999, remaining)){
                cout << "CM";
                remaining -= 900;
            } else if(between(500, 899, remaining)){
                cout << "D";
                remaining -= 500;
            } else if(between(400, 499, remaining)){
                cout << "CD";
                remaining -= 400;
            } else if(between(100, 399, remaining)){
                cout << "C";
                remaining -= 100;
            } else if(between(90, 99, remaining)){
                cout << "XC";
                remaining -= 90;
            } else if(between(50, 89, remaining)){
                cout << "L";
                remaining -= 50;
            } else if(between(40, 49, remaining)){
                cout << "XL";
                remaining -= 40;
            } else if(between(10, 39, remaining)){
                cout << "X";
                remaining -= 10;
            } else if(remaining == 9){
                cout << "IX";
                remaining -= 9;
            } else if(between(5, 8, remaining)){
                cout << "V";
                remaining -= 5;
            } else if (remaining == 4){
                cout << "IV";
                remaining -= 4;
            } else {
                cout << "I";
                remaining -= 1;
            }
        }
        cout << endl;
    } else {
        cout << "Invalid input. Program terminated.";
    }
    
    
    return 0;
}
