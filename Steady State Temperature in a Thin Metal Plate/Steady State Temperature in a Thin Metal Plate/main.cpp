//
//  main.cpp
//  Steady State Temperature in a Thin Metal Plate
//
//  Created by Jake Kaslewicz on 3/19/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
const int NCOLS = 20;
const int NROWS = 20;

void display(double temp[][NCOLS]);
void fillArray(double array[][NCOLS]);

int main(int argc, const char * argv[]) {
    double temp[NROWS][NCOLS], old[NROWS][NCOLS];
    fillArray(temp);
    display(temp);
    
    double convergence;
    cout << "Input Convergence Criteria: ";
    cin >> convergence;
    
    
    bool steady = false;
    while(!steady){
        steady = true;
        for(int i = 0; i < NCOLS ; i++){
            for(int j = 0; j < NROWS; j++){
                old[i][j] = temp[i][j];
            }
        }
        for(int i = 1; i < NCOLS - 1; i++){
            for(int j = 1; j < NROWS - 1; j++){
                old[i][j] = temp[i][j];
                temp[i][j] = 0.25 * (old[i][j - 1] + old[i][j + 1] + old[i - 1][j] + old[i + 1][j]);
                if((temp[i][j] - old[i][j]) > convergence){
                    steady = false;
                }
            }
        }
    }
    
    display(temp);
    
    return 0;
}

void display(double temp[][NCOLS]){
    for(int i = 0; i < NCOLS; i++){
        for(int j = 0; j < NROWS; j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

void fillArray(double array[][NCOLS]){
    double top, bottom, left, right, inside;
    cout << "Enter the temperature of the top side: ";
    cin >> top;
    cout << "Enter the temperature of the left side: ";
    cin >> left;
    cout << "Enter the temperature of the right side: ";
    cin >> right;
    cout << "Enter the temperature of the bottom side: ";
    cin >> bottom;
    cout << "Enter the temperature of the inside: ";
    cin >> inside;
    
    for(int i = 0; i < NCOLS; i++){
        for(int j = 0; j < NROWS; j++){
            if(i == 0){
                array[i][j] = top;
            } else if(i == (NCOLS - 1)){
                array[i][j] = bottom;
            } else if(j == 0){
                array[i][j] = left;
            } else if(j == (NROWS - 1)){
                array[i][j] = right;
            } else {
                array[i][j] = inside;
            }
        }
    }
}
