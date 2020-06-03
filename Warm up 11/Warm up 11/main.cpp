//
//  main.cpp
//  Warm up 11
//
//  Created by Jake Kaslewicz on 4/17/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int * randArray(int n);

int main(int argc, const char * argv[]) {
    double *d_var;
    double *d_array;
    
    d_var = new double;
    d_array = new double[10];
    
    cin >> *d_var;
    
    for(int i = 0; i < 10; i++){
        d_array[i] = 1.0;
    }
    
    delete d_var;
    delete []d_array;
    
    
    // 2 10 2
    
    // Delete the array after use
    
    //Timer *timePtr = new Timer(10,20);
    
    int * array = randArray(100);
    
    for(int i = 0; i < 100; i++){
        cout << array[i] << " ";
    }
    
    delete []array;
    
    
    return 0;
}

int * randArray(int n){
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        array[i] = rand();
    }
    return array;
}
