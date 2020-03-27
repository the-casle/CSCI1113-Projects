//
//  main.cpp
//  Warm Up week 8
//
//  Created by Jake Kaslewicz on 3/27/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

void reverseNum(int n);
int maxValue( int vals[], int size, int start );

int main(int argc, const char * argv[]) {
    reverseNum(5786);
    int array[5] = {55,3,77,2,56};
    cout << maxValue(array, 5, 0) << endl;
    return 0;
}

void reverseNum(int n){
    if(n < 10) cout << n << endl;
    else {
        cout << n % 10;
        reverseNum(n / 10);
    }
}

int maxValue(int vals[], int size, int start ){
    if(size == 1) return vals[start];
    else {
        if(vals[start] > vals[start + size - 1]){
            return maxValue(vals, size - 1, start);
        } else {
            return maxValue(vals, size - 1, start + 1);
        }
    }
}
