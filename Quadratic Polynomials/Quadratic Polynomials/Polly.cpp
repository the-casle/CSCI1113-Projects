//
//  Polly.cpp
//  Quadratic Polynomials
//
//  Created by Jake Kaslewicz on 4/16/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include "Polly.hpp"
#include <cmath>

Polly::Polly(){
    a = 0;
    b = 0;
    c = 0;
}

Polly::Polly(double aV, double bV, double cV){
    a = aV;
    b = bV;
    c = cV;
}

Polly Polly:: operator +(const Polly& polly){
    return Polly(a + polly.a, b + polly.b, c + polly.c);
}

double Polly::eval(double x){
    return (a * x * x) + (b * x) + c;
}
void Polly::roots(Complex& root1, Complex& root2){
    double disc = (b * b) - (4 * a * c);

    if(disc > 0){
        root1 = Complex((-b + sqrt(disc))/(2 * a), 0);
        root2 = Complex((-b - sqrt(disc))/(2 * a), 0);
    } else {
        double realV = (-b / (2 * a));
        
        root1 = Complex(realV, (sqrt((4 * a * c) - b * b) / (2 * a)));
        root2 = Complex(realV, -(sqrt((4 * a * c) - b * b) / (2 * a)));
    }
}

ostream& operator <<(ostream& ots, Polly& polly){
    ots << polly.a << "x^2";
    if(polly.b >= 0) ots << " + " << polly.b;
    else ots << " - " << -(polly.b);
    ots << "x";
    if(polly.c >= 0) ots << " + " << polly.c;
    else ots << " - " << -(polly.c);
    return ots;
}

istream& operator >>(istream& ins, Polly& polly){
    double a, b, c;
    ins >> a >> b >> c;
    polly = Polly(a, b, c);
    return ins;
}
