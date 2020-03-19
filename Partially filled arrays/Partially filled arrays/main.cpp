//
//  main.cpp
//  Partially filled arrays
//
//  Created by Jake Kaslewicz on 3/19/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>

using namespace std;

void printingRequest(string names[], int heights[], int partners);
string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();

const int MAXIMUM_PARTNERS = 100;

int main() {
    int partners = requestNumberOfPartners();
    string names[MAXIMUM_PARTNERS];
    int heights[MAXIMUM_PARTNERS];
    
    for(int i = 0; i < partners; i++){
        names[i] = requestName();
        heights[i] = requestHeight(names[i]);
    }
    printingRequest(names, heights, partners);
}

void printingRequest(string names[], int heights[], int partners){
    cout << "If ";
    int totalHeight = 0;
    for(int i = 0; i < partners; i ++) {
        cout << names[i];
        if(i != (partners - 1)) cout << " and ";
        totalHeight += heights[i];
    }
    cout << " stand on top of each other, their combined height will be " << totalHeight << endl;
}

string requestName() {
    string name;
    cout << "Please enter full name: ";
    getline(cin, name);
    return name;
}

double requestHeight(string fullName)
{
    double height;
    cout << "Please enter " << fullName << "'s height: ";
    cin >> height;
    cin.ignore(2, '\n'); // gets rid of \n in the buffer
    
    return height;
}

int requestNumberOfPartners() {
    int numberOfPartners;
    cout << "How many partners are there? ";
    cin >> numberOfPartners;
    cin.ignore(2, '\n'); // gets rid of \n in the buffer
    
    return numberOfPartners;
}
