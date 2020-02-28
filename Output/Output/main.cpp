//
//  main.cpp
//  Output
//
//  Created by Jake Kaslewicz on 2/28/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int month, day, year;
    char spacing;
    cout << "Enter a date in mm/dd/yyyy format: ";
    cin >> month >> spacing >> day >> spacing >> year;
    
    cout << "Year, month, day: " << year << "," << month << "," << day << endl;
    
    return 0;
}
