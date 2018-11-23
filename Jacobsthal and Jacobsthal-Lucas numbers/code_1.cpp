//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
 
int Jacobsthal(int n) { 
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    } 
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2); 
} 

int Jacobsthal_Lucas(int n) { 
    if (n == 0) {
        return 2;
    }
    if (n == 1) {
        return 1;
    } 
    return Jacobsthal_Lucas(n - 1) + 2 * Jacobsthal_Lucas(n - 2); 
}

int main() { 
    int n;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nJacobsthal number\t:\t" << Jacobsthal(n) << endl; 
    cout << "\nJacobsthal-Lucas number\t:\t" << Jacobsthal_Lucas(n) << endl; 
    return 0; 
} 
