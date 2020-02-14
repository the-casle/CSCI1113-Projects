//
//  main.cpp
//  Loop Equivalence
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int i = 1;
    int total = 0;
    while( i < 100 )
    {
     total += i;
     i++;
    }
    cout << total << endl;
    
    int newTotal = 0;
    for(int i = 1; i < 100; i++){
        newTotal += i;
    }
    
    cout << newTotal << endl;
    
    return 0;
}
