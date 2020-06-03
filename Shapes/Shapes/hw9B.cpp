//
//  main.cpp
//  Shapes
//
//  Created by Jake Kaslewicz on 5/1/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class shape{
public:
    shape();
    shape(double, double);
    shape operator +(shape);
    void setup();
    friend ostream& operator <<(ostream&, shape&);
    void setArea(double);
    void setPerimeter(double);
    double getArea();
    double getPerimeter();
private:
    double area;
    double perimeter;
};

class circle : public shape{
public:
    circle();
};
class triangle : public shape{
public:
    triangle();
};
class hexagon : public shape{
public:
    hexagon();
};
class rectangle : public shape{
public:
    rectangle();
};


int main()
{
    shape** list = new shape*[1000];
    int size=0;
    string choice;
    do
    {
        cout << "Do you want to add a (c)ircle, (t)riangle, (h)exagon, (r)ectangle or (q)uit?\n";
        getline(cin,choice);
        
        shape* type;
        if(choice.length()==0)
        {
            continue;
        }
        else if(tolower(choice[0]) == 'c')
        {
            type = new circle();
        }
        else if(tolower(choice[0]) == 't')
        {
            type = new triangle();
        }
        else if(tolower(choice[0]) == 'h')
        {
            type = new hexagon();
        }
        else if(tolower(choice[0]) == 'r')
        {
            type = new rectangle();
        }
        else
        {
            continue;
        }

        type->setup();
        
        list[size] = type;
        size++;

        string junk;
        getline(cin,junk);
        
    }while(choice.length()==0 || tolower(choice[0]) != 'q');

    shape total;
    for(int i=0; i < size; i++)
    {
        cout << "Shape " << i+1 << ":\n" << *list[i] << endl;
        total = total + *list[i];
    }
    cout << "Totals:\n" << total << endl;


    // memory!
    for(int i=0; i < size; i++)
    {
        delete list[i];
    }
    delete [] list;
}


shape::shape(){
    area = 0;
    perimeter = 0;
}
shape::shape(double areaV, double perV){
    area = areaV;
    perimeter = perV;
}

shape shape::operator +(shape newShape){
    return shape(area + newShape.area, perimeter + newShape.perimeter);
}

ostream& operator <<(ostream& ots, shape& newShape){
    ots << "Area: " << newShape.area << endl << "Perimter: " << newShape.perimeter << endl;
    return ots;
}

void shape::setup(){
    
}

void shape::setArea(double a){
    area = a;
}

void shape::setPerimeter(double p){
    perimeter = p;
}

double shape::getArea(){
    return area;;
}

double shape::getPerimeter(){
    return perimeter;
}

circle::circle(){
    double r;
    cout << "What is the radius of the circle?\n";
    cin >> r;
    setArea(M_PI * r*r);
    setPerimeter(2*M_PI*r);
}

triangle::triangle(){
    double s1, s2, s3;
    cout << "What are the lengths of the triangle sides?\n";
    cin >> s1 >> s2 >> s3;
    double s = (s1+s2+s3)/2;
    setArea(sqrt(s*(s-s1)*(s-s2)*(s-s3)));
    setPerimeter(s1 + s2 + s3);
}

hexagon::hexagon(){
    double l;
    cout << "What is the side length of the regular hexagon?\n";
    cin >> l;
    setArea(3*sqrt(3)*l*l/2);
    setPerimeter(6*l);
}

rectangle::rectangle(){
    cout << "What are the width and height of the rectangle?\n";
    double w,h;
    cin >> w >> h;
    setArea(w*h);
    setPerimeter(2*w+2*h);
}
