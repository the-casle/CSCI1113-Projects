//
//  main.cpp
//  Nested Loops
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << (i * j) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
