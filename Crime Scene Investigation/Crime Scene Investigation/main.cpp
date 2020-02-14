//
//  main.cpp
//  Crime Scene Investigation
//
//  Created by Jake Kaslewicz on 2/14/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double initialTemperature, surroundingTemperature, rateChange, timeStep, simLength;
    
    cout << "Enter the intial temperature: ";
    cin >> initialTemperature;
    cout << "Enter the temperature of the surroundings: ";
    cin >> surroundingTemperature;
    cout << "Enter the growth (decay) rate: ";
    cin >> rateChange;
    cout << "Enter the time step in hours: ";
    cin >> timeStep;
    cout << "Enter the simulation length in hours: ";
    cin >> simLength;
    
    double elaspsedTime = 0;
    double adjustedTemperature = initialTemperature;
    
    while(elaspsedTime <= simLength){
        adjustedTemperature = adjustedTemperature + rateChange * (surroundingTemperature - adjustedTemperature) * timeStep;
        elaspsedTime += timeStep;
        
        cout << fixed << elaspsedTime << "   " << adjustedTemperature << endl;
    }

    return 0;
}
