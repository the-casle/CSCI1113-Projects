//
//  main.cpp
//  Factorial
//
//  Created by Jake Kaslewicz on 4/2/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int factorial(int n);

int main(int argc, const char * argv[]) {
    cout << factorial(5) << endl;

    return 0;
}

int factorial(int n){
    if(n == 1) return 1;
    else{
        return n * factorial(n - 1);
    }
}
