//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int countAllWays(int n) {
    int table[n + 1];
    for(int j = 0; j < n + 1; j++) {
        table[j] = 0;
    }
    table[0] = 1;
    for (int i = 3; i <= n; i++) {
        table[i] += table[i - 3];
    }
    for (int i = 5; i <= n; i++) {
        table[i] += table[i - 5];
    }
    for (int i = 10; i <= n; i++) {
        table[i] += table[i - 10];
    }
    return table[n];
}

int main() {
    int n;
    cout << "\nEnter Number\t:\t";
    cin >> n;
    cout << "\nTotal Number of Ways\t:\t " << countAllWays(n) << "\n";
    
    return 0;
}

