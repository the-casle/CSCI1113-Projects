//
//  main.cpp
//  Binomial Coefficients
//
//  Created by Jake Kaslewicz on 4/2/20.
//  Copyright © 2020 Jake Kaslewicz. All rights reserved.
//

#include <iostream>
using namespace std;

int choose(int n,int k);

int main(int argc, const char * argv[]) {
    cout << choose(10, 2) << endl;
    
    return 0;
}

int choose(int n,int k){
    if(k <= 0 || n == k){
        return 1;
    } else{
        return choose(n - 1, k - 1) + choose(n - 1, k);
    }
}
