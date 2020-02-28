//
//  main.cpp
//  Big Bad Integer Calculator
//
//  Created by Jake Kaslewicz on 2/21/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout<< "Enter a formula: \n";
    double num;
    int result;
    char function;
    char last = '*';
    
    cin >> result;
    
    while(last != '#') {
        cin >> function;
        if(function == '*'){
            cin >> num;
            result *= num;
        } else if(function == '/') {
            cin >> num;
            result /= num;
        } else if(function == '+') {
            cin >> num;
            result += num;
        } else if(function == '-'){
            cin >> num;
            result -= num;
        }
        last = function;
    }
    cout << result << endl;
    return 0;
}
