//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<bits/stdc++.h>
using namespace std;

unsigned long int binomialCoeff(unsigned int n, unsigned int k)  { 
    unsigned long int res = 1; 
    if (k > n - k) 
        k = n - k; 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 
unsigned long int catalan(unsigned int n) { 
    unsigned long int c = binomialCoeff(2*n, n); 
    return c/(n+1); 
}

int main () {
    cout << "\nEnter Number\t:\t";
    unsigned int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << catalan(number);
    cout << endl;
    return 0;
}
