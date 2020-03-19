//
//  main.cpp
//  Time Conversion, Part 2
//
//  Created by Jake Kaslewicz on 2/28/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

void minutesToTime(int minute_value, int& hours, int& mins);

int main(int argc, const char * argv[]) {
    bool continueRunning = true;
          while(continueRunning){
              
              int input, hours, minutes;
              
              cout << "Enter a number of minutes: ";
              cin >> input;
              
              minutesToTime(input, hours, minutes);
              cout << "Hours:minutes is: " << hours << ":";
              if(minutes < 10) cout << "0";
              cout << minutes << endl;
              
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

void minutesToTime(int minute_value, int& hours, int& mins){
    hours = minute_value / 60;
    mins = minute_value % 60;
}
