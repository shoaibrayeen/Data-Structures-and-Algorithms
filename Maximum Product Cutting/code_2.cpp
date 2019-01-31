//
//  code_2.cpp
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
    int val[n+1];
    val[0] = val[1] = 0;
    for (int i = 1; i <= n; i++) {
        int max_val = 0;
        for (int j = 1; j <= i/2; j++)
            max_val = max(max_val, (i-j)*j, j*val[i-j]);
        val[i] = max_val;
    }
    return val[n];
}

int main() {
    int n;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nMaximum Product\t:\t" << getMaxProd(n) << "\n";
    return 0;
}
