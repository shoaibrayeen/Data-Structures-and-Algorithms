//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
 
int eulerian(int n, int m) { 
    if (m >= n || n == 0) {
        return 0; 
    }
    if (m == 0) {
        return 1;
    }
    return (n - m) * eulerian(n - 1, m - 1) + (m + 1) * eulerian(n - 1, m); 
}  
  
int main() { 
    int n , m;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nEnter m\t:\t";
    cin >> m;
    cout << eulerian(n, m) << endl; 
    return 0; 
} 
