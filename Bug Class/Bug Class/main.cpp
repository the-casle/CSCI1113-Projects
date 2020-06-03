//
//  main.cpp
//  Bug Class
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include "Bug.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Bug newBug;
    newBug.set(10);
    newBug.display();
    newBug.move();
    newBug.display();
    newBug.turn();
    newBug.display();
    newBug.move();
    newBug.display();
    
    
    return 0;
}
