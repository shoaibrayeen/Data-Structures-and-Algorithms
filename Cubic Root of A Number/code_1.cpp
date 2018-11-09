//
//  q5.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 05/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 

double diff( double n , double mid ) { 
    if (n > (mid*mid*mid)) {
        return (n-(mid*mid*mid)); 
    }
    else {
        return ((mid*mid*mid) - n); 
    }
} 
  
double cubicRoot(double n) {
    double start = 0, end = n; 
    double e = 0.0000001; 
    while (true) 
    { 
        double mid = (start + end)/2; 
        double error = diff(n, mid); 
        if (error <= e) {
            return mid; 
        }
        if ((mid*mid*mid) > n) {
            end = mid; 
        }  
        else {
            start = mid; 
        }
    } 
} 
  
int main() { 
    double num;
    cout << "\nEnter Number\t:\t";
    cin >> num;
    cout << "\nCubic Root\t:\t" << cubicRoot(num);
    return 0; 
}
