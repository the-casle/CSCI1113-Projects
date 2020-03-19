//
//  main.cpp
//  Flight Arrival Statistics
//
//  Created by Jake Kaslewicz on 3/4/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>

void elapsedTime(int h1, int m1, int h2, int m2, int& h, int& m);
void minutesToTime(int minute_value, int& hours, int& mins);
int timeToMinutes(int hour, int minutes);

using namespace std;
int main(int argc, const char * argv[]) {
    ifstream inStream;
    string dataName;
    
    cout << "Enter the name of the file that stores the flight data:\n";
    cin >> dataName;
    
    inStream.open(dataName.c_str());
    if(inStream.fail()){
        cout << "Unable to open file.\n";
        exit(1);
    }
    
    string line;
    int lineCount = 0;
    int totalDelay = 0;
    int averageDelay = 0;
    string flightName;
    int hour1, min1, hour2, min2;
    char colon;
    int elapsedHours, elapsedMinutes;
    
    string flightNameMinimum, flightNameMaximum;
    int minuteMinimum = 0, minuteMaximum = 0;
    
    while (inStream >> flightName >> hour1 >> colon >> min1 >> hour2 >> colon >> min2){
        elapsedTime(hour1, min1, hour2, min2, elapsedHours, elapsedMinutes);
        int delayInMinutes = timeToMinutes(elapsedHours, elapsedMinutes);
        
        if(lineCount == 0){
            minuteMinimum = delayInMinutes;
            minuteMaximum = delayInMinutes;
        }
        if(delayInMinutes >= minuteMaximum){
            flightNameMaximum = flightName;
            minuteMaximum = delayInMinutes;
        }
        if(delayInMinutes <= minuteMinimum){
            minuteMinimum = delayInMinutes;
            flightNameMinimum = flightName;
        }
        
        totalDelay += delayInMinutes;
        
        lineCount++;
    }
    averageDelay = totalDelay / lineCount;
    cout << "The average delay is: " << averageDelay << endl;
    
    int minHour, minMin, maxHour, maxMin;
    minutesToTime(minuteMinimum, minHour, minMin);
    minutesToTime(minuteMaximum, maxHour, maxMin);
    
    cout << "The flight number " << flightNameMinimum << " has the minimum delay of: " << minHour << ":";
    if(minMin < 10) cout << "0";
    cout << minMin << endl;
    
    cout << "The flight number " << flightNameMaximum << " has the maximum delay of: " << maxHour << ":";
    if(maxMin < 10) cout << "0";
    cout << maxMin << endl;
    
    inStream.close();
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
