//
//  main.cpp
//  Zodiac Sign
//
//  Created by Jake Kaslewicz on 2/12/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    double month, day;
    char divider;
    
    cout << "Enter the month/day when you were born:\n";
    cin >> month;
    cin >> divider;
    cin >> day;
    
    string zodiac;
    
    if(month <= 12){
        if((month == 3 && day >= 21) || (month == 4 && day <= 19)){
            zodiac = "Aries";
        } else if((month == 4 && day >= 20) || (month == 5 && day <= 20)){
            zodiac = "Taurus";
        } else if((month == 5 && day >= 21) || (month == 6 && day <= 20)){
            zodiac = "Gemini";
        } else if((month == 6 && day >= 21) || (month == 7 && day <= 22)){
            zodiac = "Cancer";
        } else if((month == 7 && day >= 23) || (month == 8 && day <= 22)){
            zodiac = "Leo";
        } else if((month == 8 && day >= 23) || (month == 9 && day <= 22)){
            zodiac = "Virgo";
        } else if((month == 9 && day >= 23) || (month == 10 && day <= 22)){
            zodiac = "Libra";
        } else if((month == 10 && day >= 23) || (month == 11 && day <= 21)){
            zodiac = "Scorpio";
        } else if((month == 11 && day >= 22) || (month == 12 && day <= 21)){
            zodiac = "Sagittarius";
        } else if((month == 12 && day >= 22) || (month == 1 && day <= 19)){
            zodiac = "Capricorn";
        } else if((month == 1 && day >= 20) || (month == 2 && day <= 18)){
            zodiac = "Aquarius";
        } else {
            zodiac = "Pisces";
        }
        
        cout << zodiac << endl;
        
    } else {
        cout << "Invalid month\n";
    }
    
    return 0;
}
