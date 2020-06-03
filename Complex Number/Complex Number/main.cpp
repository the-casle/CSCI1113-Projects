//
//  main.cpp
//  Complex Number
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"
using namespace  std;

int main(int argc, const char * argv[]) {
    Complex c1, c2, c3;
    cout << "Enter two complex values: ";
    cin >> c1 >> c2;
    
    c3 = c1 + c2;
    
    cout << "The sum is: " << c3 << endl;
    c3 = -c3;
    cout << "and negating the sum yields: " << c3 << endl;
    
    return 0;
}
