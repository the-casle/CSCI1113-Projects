//
//  main.cpp
//  Collatz Problem
//
//  Created by Jake Kaslewicz on 4/3/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int collatz(int i);

int main(int argc, const char * argv[]) {
    cout << "Enter first/initial number:\n";
    int n;
    cin >> n;
    cout << collatz(n) << endl;
    
    return 0;
}

int collatz(int i){
    if(i == 1) return 1;
    
    int value = i;
    cout << value << " ";
    
    if(i % 2 == 0){ // Even.
        value = collatz(i / 2);
    } else { // Odd.
        value = collatz(3 * i + 1);
    }
    return value;
}
