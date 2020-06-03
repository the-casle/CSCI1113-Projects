//
//  Bug.cpp
//  Bug Class
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include "Bug.hpp"
#include <iostream>

void Bug::set(){
    position = 0;
    dir = 1;
}

void Bug::set(int pos){
    position = pos;
    dir = 1;
}

void Bug::move(){
    position += dir;
}
void Bug::turn(){
    dir = (dir > 0 ? -1 : 1);
}
void Bug::display(){
    using namespace std;
    cout << "position = " << position << ", direction = " << dir << endl;
}
