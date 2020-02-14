//
//  main.cpp
//  Fibonacci Numbers
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    double iterations;
    cout << "How many fibonacci numbers should be output?\n";
    cin >> iterations;
    
    double previousFibonacci = 0;
    double currentFibonacci = 1;
    
    for(int i = 0; i < iterations; i++){
        double temp = currentFibonacci + previousFibonacci;
        previousFibonacci = currentFibonacci;
        currentFibonacci = temp;
        
        cout << previousFibonacci << endl;
    }
    
    
    return 0;
}
