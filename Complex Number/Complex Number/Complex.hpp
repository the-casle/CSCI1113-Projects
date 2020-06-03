//
//  Complex.hpp
//  Complex Number
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include <fstream>

using namespace std;

class Complex{
public:
    Complex();
    Complex(double, double);
    double getReal();
    double getImag();
    void setReal(double r);
    void setImag(double i);
    
    Complex operator +(Complex);
    Complex operator -();
    
    friend ostream& operator <<(ostream& ots, Complex& complex);
    friend istream& operator >>(istream& ins, Complex& complex);
    
private:
    double real;
    double imaginary;
};


#endif /* Complex_hpp */
