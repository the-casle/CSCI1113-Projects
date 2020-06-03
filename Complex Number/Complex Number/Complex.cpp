//
//  Complex.cpp
//  Complex Number
//
//  Created by Jake Kaslewicz on 4/9/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include "Complex.hpp"

Complex::Complex(){
    real = 0;
    imaginary = 0;
}

Complex::Complex(double realV, double imagV){
    real = realV;
    imaginary = imagV;
}

double Complex::getReal(){
    return real;
}
double Complex::getImag(){
    return imaginary;
}
void Complex::setReal(double r){
    real = r;
}
void Complex::setImag(double i){
    imaginary = i;
}

Complex Complex::operator +(Complex complex){
    return Complex(real + complex.real, imaginary + complex.imaginary);
}

Complex Complex::operator -(){
    return Complex(-real, -imaginary);
}

ostream& operator <<(ostream& ots, Complex& complex){
    ots << complex.real;
    if(complex.imaginary > 0){
        ots <<  " + " << complex.imaginary << "i";
    } else if(complex.imaginary < 0) {
        ots << " - " << -(complex.imaginary) << "i";
    }
    return ots;
}

istream& operator >>(istream& ins, Complex& complex){
    double r, i;
    ins >> r >> i;
    complex = Complex(r,i);
    return ins;
}
