//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int getMaxProd(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    int max_val = 0;
    for (int i = 1; i < n; i++) {
        max_val = max(max_val, i*(n-i), getMaxProd(n-i)*i);
    }
    return max_val;
}

int main() {
    int n;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nMaximum Product\t:\t" << getMaxProd(n) << "\n";
    return 0;
}
