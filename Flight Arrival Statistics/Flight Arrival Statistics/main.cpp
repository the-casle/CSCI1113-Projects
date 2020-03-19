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
    while (getline(inStream, line)){
        lineCount++;
    }
    
    cout << lineCount << endl;
    int totalDelay = 0;
    int averageDelay = 0;
    for(int i = 0; i < lineCount; i++){
        string flightName;
        int hour1, min1, hour2, min2;
        string colon;
        inStream >> flightName >> hour1 >> colon >> min1 >> hour2 >> colon >> min2;
        cout << flightName;
        int elapsedHours, elapsedMinutes;
        elapsedTime(hour1, min1, hour2, min2, elapsedHours, elapsedMinutes);
        totalDelay += timeToMinutes(elapsedHours, elapsedMinutes);
        averageDelay = totalDelay / lineCount;
    }
    
    cout << averageDelay << endl;
    
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
