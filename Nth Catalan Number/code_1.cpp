//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

unsigned long int catalan(unsigned int n) { 
    if (n <= 1) return 1;
    unsigned long int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
    return res; 
} 
  
int main () {
    cout << "\nEnter Number\t:\t";
    unsigned int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << catalan(number);
    cout << endl;
    return 0;
}
