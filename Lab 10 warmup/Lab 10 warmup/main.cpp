//
//  main.cpp
//  Lab 10 warmup
//
//  Created by Jake Kaslewicz on 4/16/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

class Point{
public:
    Point( );
    Point(int xval, int yval);
    Point operator +(Point);
    friend Point operator +(Point, Point);
    friend ostream& operator <<(ostream& ins, Point& point);
    
private:
    int xloc;
    int yloc;
} ;

int main(int argc, const char * argv[]) {
    
    return 0;
}


Point operator +(Point point1, Point point2){
    Point temp;
    temp.xloc = point1.xloc + point2.xloc;
    temp.yloc = point1.yloc + point2.yloc;
    return temp;
}

Point Point::operator +(Point point){
    return Point(xloc + point.xloc, yloc + point.yloc);
}

/* D It returns a stream because its really just nested streams.
E Not sure why it is actually
 */

ostream& operator <<(ostream& ins, Point& point){
    ins << point.xloc << ", " << point.yloc << endl;
    return ins;
}
