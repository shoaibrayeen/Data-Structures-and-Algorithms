//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

unsigned long int catalanDP(unsigned int n)  { 
    int catalan[n+1];
    catalan[0] = catalan[1] = 1; 
    for (int i = 2; i <= n; i++) { 
        catalan[i] = 0; 
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i-j-1]; 
        }
    } 
    return catalan[n]; 
} 

int main () {
    cout << "\nEnter Number\t:\t";
    unsigned int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << catalanDP(number);
    cout << endl;
    return 0;
}
