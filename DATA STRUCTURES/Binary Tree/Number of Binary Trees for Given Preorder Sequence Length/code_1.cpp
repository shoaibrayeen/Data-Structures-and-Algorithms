//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int countTrees(int n) {
    int BT[n + 1];
    memset(BT, 0, sizeof(BT));
    
    BT[0] = BT[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; j++) {
            BT[i] += BT[j] * BT[i - j - 1];
        }
    }
    return BT[n];
}

int main() {
    cout << "\nEnter Sequence Length\t:\t";
    int n;
    cin >> n;
    cout << "\nTotal Possible Binary Tree\t:\t" << countTrees(n) << endl;
    return 0;
}
