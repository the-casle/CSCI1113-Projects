//
//  main.cpp
//  Greatest Common Divisor
//
//  Created by Jake Kaslewicz on 4/2/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(int argc, const char * argv[]) {
    cout << gcd(1260,198) << endl;
    cout << gcd(197,13) << endl;
    cout << gcd(120,60) << endl;
    
    
    return 0;
}

int gcd(int a, int b){
    if(b == 0) return a;
    else {
        int r = a % b;
        if(r == 0) return b;
        else return gcd(b, r);
    }
}
