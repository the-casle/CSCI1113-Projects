//
//  main.cpp
//  Flight Data Collection
//
//  Created by Jake Kaslewicz on 3/2/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ofstream outStream;
    outStream.open("flightData.dat");
    if(outStream.fail()){
        cout << "Unable to open file.\n";
        exit(1);
    }
    string flightNumber;
    while(flightNumber != "end"){
        double hour1, min1, hour2, min2;
        char colon;
        
        cout << "Enter the flight number: ";
        cin >> flightNumber;
        if(flightNumber == "end") break;
        cout << "Enter the scheduled/actual arrival times: ";
        cin >> hour1 >> colon >> min1 >> hour2 >> colon >> min2;
        
        
        outStream << flightNumber << " " << hour1 << ":";
        if(min1 < 10){
            outStream << "0";
        }
        outStream << min1 << " " << hour2 << ":";
        if(min2 < 10){
            outStream << "0";
        }
        outStream << min2 << "\n";
    }
    outStream.close();
    
    return 0;
}
