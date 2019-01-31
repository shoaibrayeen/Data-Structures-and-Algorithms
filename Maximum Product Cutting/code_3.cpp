//
//  code_3.cpp
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
    if (n == 2 || n == 3) {
        return (n-1);
    }
    int res = 1;
    while (n > 4) {
        n -= 3;
        res *= 3;
    }
    return (n * res);
}

int main() {
    int n;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nMaximum Product\t:\t" << getMaxProd(n) << "\n";
    return 0;
}
