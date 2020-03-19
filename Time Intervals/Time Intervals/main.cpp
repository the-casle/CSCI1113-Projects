//
//  main.cpp
//  Time Intervals
//
//  Created by Jake Kaslewicz on 2/28/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void elapsedTime(int h1, int m1, int h2, int m2, int& h, int& m);
int timeToMinutes(int hour, int minutes);
void minutesToTime(int minute_value, int& hours, int& mins);

int main(int argc, const char * argv[]) {
    bool continueRunning = true;
    while(continueRunning){
        int hour1, minutes1, hour2, minutes2, hourDifference, minuteDifference;
        char spacing;
        
        cout << "Enter first time (hours:minutes) : ";
        cin >> hour1 >> spacing >> minutes1;
        cout << "Enter second time (hours:minutes) : ";
        cin >> hour2 >> spacing >> minutes2;
        
        
        elapsedTime(hour1, minutes1, hour2, minutes2, hourDifference, minuteDifference);
        cout << "Elapsed time is: " << hourDifference << ":";
        if(minuteDifference < 10) cout << "0";
        cout << minuteDifference << endl;
        
        cout << "Continue? (y/n): ";
        char continueRunningString;
        cin >> continueRunningString;
        if(continueRunningString == 'y'){
            continueRunning = true;
        } else {
            continueRunning = false;
        }
    }
    
    return 0;
}

void elapsedTime(int h1, int m1, int h2, int m2, int& h, int& m){
    int h1InMinutes = timeToMinutes(h1,m1);
    int h2InMinutes = timeToMinutes(h2, m2);
    
    int differenceMinutes = fabs(h1InMinutes - h2InMinutes);
    minutesToTime(differenceMinutes, h, m);
}

void minutesToTime(int minute_value, int& hours, int& mins){
    hours = minute_value / 60;
    mins = minute_value % 60;
}

int timeToMinutes(int hour, int minutes){
    return (minutes + hour * 60);
}
