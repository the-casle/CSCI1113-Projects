//
//  Bug.hpp
//  Bug Class
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#ifndef Bug_hpp
#define Bug_hpp

#include <stdio.h>

class Bug {
public:
    void set();
    void set(int pos);
    void move();
    void turn();
    void display();
private:
    int position;
    int dir;
};

#endif /* Bug_hpp */
