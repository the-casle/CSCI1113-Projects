//
//  main.cpp
//  Practice
//
//  Created by Jake Kaslewicz on 5/12/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

const char* strTocstr(string s);
int main() {
    string x = "something";
    cout << x << endl << strTocstr(x) << endl;
}

const char* strTocstr(string s){
    char *cstr;
    cstr = new char[s.length() + 1];
    for(int i = 0; i < s.length(); i++){
        cstr[i] = s.at(i);
    }
    cstr[s.length()] = '\0';
    return cstr;
}
