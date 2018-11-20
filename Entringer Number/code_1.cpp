//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
  
int Entringer_Number(int n, int k) { 
    if (n == 0 && k == 0) {
        return 1; 
    }
    if (k == 0) {
        return 0;
    }
    return Entringer_Number(n, k - 1) + Entringer_Number(n - 1, n - k); 
} 
  
int main() { 
    int n;
    cout << "\nEnter n\t:\t";
    int number;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nEntringer Number\t:\t" << Entringer_Number(n, k) << endl; 
    return 0; 
} 
