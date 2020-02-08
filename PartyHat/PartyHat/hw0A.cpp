//
//  main.cpp
//  PartyHat
//
//  Created by Jake Kaslewicz on 2/4/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#import <iostream>
#import <cmath>
using namespace std;

int main() {
    
    const double angle = M_PI / 2;
    
    double arcLength;
    cout << "What length did you measure (in cm)?\n";
    cin >> arcLength;
    double chordLength = ((2 * arcLength) / angle) * sin(angle/2);
    double radius = chordLength / 2;
    double surfaceArea = M_PI * radius * sqrt((radius * radius) + 900);
    
    cout << "Surface area is:\n" << surfaceArea << endl;
    return 0;
}
