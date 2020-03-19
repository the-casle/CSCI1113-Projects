//
//  main.cpp
//  Time Conversion
//
//  Created by Jake Kaslewicz on 2/28/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int timeToMinutes (int hours, int mins);

int main(int argc, const char * argv[]) {
    bool continueRunning = true;
       while(continueRunning){
           
           int hours, minutes;
           char spacing;
           
           cout << "Enter a time duration (hh:mm) ";
           cin >> hours >> spacing >> minutes;
           
           int totalMinutes = timeToMinutes(hours, minutes);
           cout << "Total minutes: " << totalMinutes << endl;
           
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

int timeToMinutes (int hours, int mins){
    return (mins + hours * 60);
}
