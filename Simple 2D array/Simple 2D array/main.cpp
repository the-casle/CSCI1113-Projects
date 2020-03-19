//
//  main.cpp
//  Simple 2D array
//
//  Created by Jake Kaslewicz on 3/6/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int matrix[3][3];
    int count = 10;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = count;
            cout << count << " ";
            count--;
        }
        cout << endl;
    }
    
    return 0;
}
