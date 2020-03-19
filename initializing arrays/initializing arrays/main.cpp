//
//  main.cpp
//  initializing arrays
//
//  Created by Jake Kaslewicz on 3/6/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();


int main()
{
    string names[2];
    int heights[2];
    names[0] = requestName();
    heights[0] = requestHeight(names[0]);
    names[1] = requestName();
    heights[1] = requestHeight(names[1]);

    cout << "If " << names[0] << " and " << names[1]
            << " stand on top of each other, their combined height will be "
            << (heights[0] + heights[1]) << endl;
    
}

string requestName()
{
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

int requestNumberOfPartners()
{
    int numberOfPartners;
    cout << "How many partners are there? ";
    cin >> numberOfPartners;
    
    return numberOfPartners;
}
