//
//  main.cpp
//  Leap Year
//
//  Created by Jake Kaslewicz on 2/21/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

bool isLeapYear(int year);
int lastDay(int month, int year);

int main(int argc, const char * argv[]) {
    bool continueRunning = true;
    while(continueRunning){
        
        int month;
        int day;
        int year;
        cout << "Enter a date as mm dd yyyy: ";
        cin >> month;
        cin >> day;
        cin >> year;
        
        if(day == lastDay(month, year)){
            if(month == 12){
                month = 1;
                day = 1;
                year ++;
            } else {
                month ++;
                day = 1;
            }
        } else {
            day ++;
        }
        
        cout << "Next day is: " << month << " " << day << " " << year << endl;
        
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

bool isLeapYear(int year){
    if(year % 4 == 0){
        if(year % 100 == 0 && year % 400 != 0){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int lastDay(int month, int year){
    if(month == 2){
        if(isLeapYear(year)){
            return 29;
        } else {
            return 28;
        }
    }
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        default:
            return 30;
            break;
    }
}
