//
//  main.cpp
//  Days until summer
//
//  Created by Jake Kaslewicz on 2/28/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void elapsedDays(int m1, int d1,int y1, int m2, int d2, int y2, int &d);
int dateToDays(int m, int d, int y);
int daysInMonth(int month, int year);
bool isLeapYear(int year);

int main(int argc, const char * argv[]) {
    bool continueRunning = true;
    while(continueRunning){
        int month1, day1, year1, month2, day2, year2, dayDifference;
        char spacing;
        
        cout << "Enter start date (no spaces):\n";
        cin >> month1 >> spacing >> day1 >> spacing >> year1;
        cout << "Enter end date (no spaces):\n";
        cin >> month2 >> spacing >> day2 >> spacing >> year2;
        
        elapsedDays(month1, day1, year1, month2, day2, year2, dayDifference);
        if(dayDifference > 0){
            cout << "You have to wait: " << dayDifference;
            cout << ((dayDifference == 1) ? " Day" : " Days") << endl;
        } else {
            cout << "Never...\n";
        }
        
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

void elapsedDays(int m1, int d1,int y1, int m2, int d2, int y2, int &d){
    d = dateToDays(m2,d2,y2) - dateToDays(m1,d1,y1);
}

int dateToDays(int m, int d, int y){
    int totalDays = d;
    for(int i = (m - 1); i > 0; i--){
        totalDays += daysInMonth(i, y);
    }
    for(int i = (y - 1); i > 0; i--){
        if(isLeapYear(i)){
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }
    return totalDays;
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

int daysInMonth(int month, int year){
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
