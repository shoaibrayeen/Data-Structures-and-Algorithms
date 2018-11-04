//
//  q4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 28/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <bits/stdc++.h> 
using namespace std; 

int minproduct(int a[], int b[], int n, int k) { 
    int diff = 0, res = 0; 
    int temp; 
    for (int i = 0; i < n; i++) { 
        int pro = a[i] * b[i]; 
        res = res + pro; 
        if (pro < 0 && b[i] < 0) {
            temp = (a[i] + 2 * k) * b[i]; 
        }
        else if (pro < 0 && a[i] < 0) {
            temp = (a[i] - 2 * k) * b[i];
        }
        else if (pro > 0 && a[i] < 0) {
            temp = (a[i] + 2 * k) * b[i];
        }
        else if (pro > 0 && a[i] > 0) {
            temp = (a[i] - 2 * k) * b[i];
        }
        int d = abs(pro - temp); 
        if (d > diff) 
            diff = d;         
    } 
    return res - diff; 
} 
  
int main() { 
    cout << "\nEnter Size\t:\t";
    int n;
    cin >> n;
    int a[n] , b[n];
    for ( int i = 0; i < n; i++ ) {
      cin >> a[i];
    }
    for ( int i = 0; i < n; i++ ) {
      cin >> b[i];
    }
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nResult\t:\t"  <<  minproduct(a, b, n, k) << endl; 
    return 0; 
} 
