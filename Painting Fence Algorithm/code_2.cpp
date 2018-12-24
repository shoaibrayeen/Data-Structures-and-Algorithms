//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;



long countWays(int n, int k) {
    long total = k;
    int mod = 1000000007;
    long same = 0, diff = k;
    for (int i = 2; i <= n; i++) {
        same = diff;
        diff = total * (k-1);
        diff = diff % mod;
        total = (same + diff) % mod;
    }
    
    return total;
}

int main() {
    int n;
    cout << "\nEnter N\t:\t";
    cin >> n;
    int k;
    cout << "\nEnter K\t:\t";
    cin >> k;
    cout << "\nNumber of Ways\t:\t" << countWays(n,k) << endl;
    return 0;
}
