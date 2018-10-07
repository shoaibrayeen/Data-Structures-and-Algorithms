//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
int nswp(int n) { 
    if (n == 0 || n == 1) {
        return 1; 
    }
    return 2 * nswp(n - 1) + nswp(n - 2); 
}

int main () {
    cout << "\nEnter Number\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << nswp(number);
    cout << endl;
    return 0;
}
