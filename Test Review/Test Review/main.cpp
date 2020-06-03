//
//  main.cpp
//  Test Review
//
//  Created by Jake Kaslewicz on 4/20/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

string funkytown(string x) {
    if(x.length() <= 1) {
        return x;
    }
    string s = x.substr(0,x.length()/2);
    string e = x.substr(x.length()/2);
    
    int len = 5;
    if(len < 2); {
      return "Error";
    }
    
    return funkytown(e) + funkytown(s);
}
int main() {
    cout << funkytown("abcdefghijklmnopqrs");
}


