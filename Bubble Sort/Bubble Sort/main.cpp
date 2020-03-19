//
//  main.cpp
//  Bubble Sort
//
//  Created by Jake Kaslewicz on 3/19/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

void bsort(int toSort[], int arrayElements);
void passThrough(int toSort[], int max);
void swap(int swap[], int first, int second);

const int MAXIMUM_ARRAY = 50;

int main(int argc, const char * argv[]) {
    // Initializing unsorted array
    int array[MAXIMUM_ARRAY];
    int start = 100;
    for(int i = 0; i < MAXIMUM_ARRAY; i++){
        array[i] = start;
        start --;
    }
    
    bsort(array, MAXIMUM_ARRAY);
    
    for(int i = 0; i < MAXIMUM_ARRAY; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void bsort(int toSort[], int arrayElements){
    for(int i = arrayElements; i >= 0; i--){
        passThrough(toSort, i);
    }
}
void passThrough(int toSort[], int max){
    for(int i = 0; i < max - 1; i++){
        if(toSort[i] > toSort[i + 1]){
            swap(toSort, i, i + 1);
        }
    }
}

void swap(int swap[], int first, int second){
    int temp = swap[first];
    swap[first] = swap[second];
    swap[second] = temp;
}
