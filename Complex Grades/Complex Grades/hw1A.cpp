//
//  main.cpp
//  Complex Grades
//
//  Created by Jake Kaslewicz on 2/12/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    char gradeType;
    int gradeValue; // Always rounds down so we can truncate
    string roughGradeLetter;
    string fineGradeSymbol = "";
    
    cout << "Fine or rough grades? (f/r): ";
    cin >> gradeType;
    cout << "Enter a score: ";
    cin >> gradeValue;
    
    if(gradeValue >= 90){
        roughGradeLetter = "A";
    } else if(gradeValue >= 80){
        roughGradeLetter = "B";
    } else if(gradeValue >= 70){
        roughGradeLetter = "C";
    } else if(gradeValue >= 60){
        roughGradeLetter = "D";
    } else {
        roughGradeLetter = "F";
    }
    
    if(gradeType == 'f'){
        int remainder = gradeValue % 10;
        if(remainder < 3){
            fineGradeSymbol = "-";
        } else if(remainder >= 7){
            fineGradeSymbol = "+";
        }
    }
    
    cout << roughGradeLetter << fineGradeSymbol << endl;
    
    return 0;
}
