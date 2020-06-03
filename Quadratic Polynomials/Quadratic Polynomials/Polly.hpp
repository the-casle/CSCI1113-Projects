//
//  Polly.hpp
//  Quadratic Polynomials
//
//  Created by Jake Kaslewicz on 4/16/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#ifndef Polly_hpp
#define Polly_hpp

#include <stdio.h>
#include <fstream>
#include "Complex.hpp"

using namespace std;

class Polly{
public:
    Polly();
    Polly(double, double, double);
    Polly operator +(const Polly&);
    double eval(double);
    void roots(Complex& root1, Complex& root2);
    
    friend ostream& operator <<(ostream& ots, Polly& polly);
    friend istream& operator >>(istream& ins, Polly& polly);
private:
    double a,b,c;
};

#endif /* Polly_hpp */
