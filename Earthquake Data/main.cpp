//
//  main.cpp
//  Earthquake Data
//
//  Created by Jake Kaslewicz on 3/19/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string nextString(string csv, int index);
int split(string str, string a[], int maxSize);

int main(int argc, const char * argv[]) {
    ifstream inStream;
    inStream.open("2.5_day.csv");
    if(inStream.fail()){
        cout << "Unable to open file.\n";
        exit(1);
    }
    
    string line;
    getline(inStream,line); // Getting rid of header.
    while(getline(inStream,line)){
        string lineArray[line.length()];
        int filled = split(line, lineArray, line.length());
        string place = lineArray[14];
        place.erase(place.length() - 1, 1);
        cout << lineArray[4] << " magnitude in" << place << endl;
    }
    
    return 0;
}

int split(string str, string a[], int maxSize){
    int commaIndex = 0;
    int arrayIndex = 0;
    while(arrayIndex < maxSize){
        a[arrayIndex] = nextString(str, commaIndex);
        commaIndex = str.find(",", commaIndex);
        if(commaIndex == string::npos){
           break;
        }
        arrayIndex ++;
        commaIndex ++;
    }
    return arrayIndex;
}

string nextString(string csv, int index){
    int length = csv.find(",",index + 1) - index;
    return csv.substr(index, length);
}
