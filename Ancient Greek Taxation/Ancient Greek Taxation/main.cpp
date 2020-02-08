//
//  main.cpp
//  Ancient Greek Taxation
//
//  Created by Jake Kaslewicz on 2/7/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#import <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double unTaxedIncome;
    double totalTax = 0;
    cout << "Income (in drachmas):\n";
    cin >> unTaxedIncome;
    
    if(unTaxedIncome >= 10000){
        unTaxedIncome -= 10000;
    } else{
        unTaxedIncome = 0;
    }
    if(unTaxedIncome >= 20000){
        totalTax += (20000 * .1);
        unTaxedIncome -= 20000;
    } else if(unTaxedIncome > 0){
        totalTax += (unTaxedIncome * .1);
        unTaxedIncome = 0;
    }
    if(unTaxedIncome >= 40000){
        totalTax += (40000 * .2);
        unTaxedIncome -= 40000;
    } else if(unTaxedIncome > 0){
        totalTax += (unTaxedIncome * .2);
        unTaxedIncome = 0;
    }
    if(unTaxedIncome > 0){
        totalTax += (unTaxedIncome * .3);
    }
    cout << "Taxed a total of: " << totalTax << " drachma(s)\n";
    
    return 0;
}
