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
    if (n == 1 || n == 0) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        return countAllWays(n - 3) + countAllWays(n - 2) + countAllWays(n - 1);
    }
}

int main() {
    int n;
    cout << "\nEnter Number\t:\t";
    cin >> n;
    cout << "\nTotal Number of Ways\t:\t " << countAllWays(n) << "\n";
    return 0;
}

