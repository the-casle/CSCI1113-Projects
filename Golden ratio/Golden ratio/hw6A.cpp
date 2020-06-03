//
//  main.cpp
//  Golden ratio
//
//  Created by Jake Kaslewicz on 4/3/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

double goldenRatio(double i);

int main(int argc, const char * argv[]) {
    int number;
    cout << "Enter number for approximation:\n";
    cin >> number;
    
    cout << goldenRatio(number) << endl;
    
    return 0;
}

double goldenRatio(double r){
    if(r == 0) return 1;
    else return 1 + (1 / goldenRatio(r - 1));
}
