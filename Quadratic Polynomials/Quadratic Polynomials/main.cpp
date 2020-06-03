//
//  main.cpp
//  Quadratic Polynomials
//
//  Created by Jake Kaslewicz on 4/16/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include "Polly.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Polly inpoly;
    cout << "Input a quadratic polynomial: ";
    cin >> inpoly;
    for( int i=0; i<= 10; i++)
     cout << "f(" << i << ") is: "
     << inpoly.eval(i) << endl;
    Complex c1,c2;
    inpoly.roots(c1,c2);
    cout << "The roots of f(x) are "
     << c1 << "\t" << c2 << endl;
    
    return 0;
}
