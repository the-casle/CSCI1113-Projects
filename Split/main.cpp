//
//  main.cpp
//  Split
//
//  Created by Jake Kaslewicz on 3/19/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


const int VALUES = 5;

string nextString(string csv, int index);
int split(string str, string a[], int maxSize);

int main(int argc, const char * argv[]) {
    string varray[VALUES];
    int cnt = split("my,cat,ate,my,homework",varray,VALUES);
    for( int i=0; i<cnt; i++)
     cout << varray[i] << endl;
    
    
    return 0;
}

int split(string str, string a[], int maxSize){
    int commaIndex = 0;
    int arrayIndex = 0;
    while(arrayIndex < maxSize){
        a[arrayIndex] = nextString(str, commaIndex);
        commaIndex = str.find(",", commaIndex) + 1;
        if(commaIndex == string::npos) break;
        arrayIndex ++;
    }
    return arrayIndex;
}

string nextString(string csv, int index){
    int length = csv.find(",",index + 1) - index;
    return csv.substr(index, length);
}
