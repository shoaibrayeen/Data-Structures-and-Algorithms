//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;

int getOptimalStrategyOfGame(vector<int>arr) {
    int n = int(arr.size());
    int table[n][n];
    for (int k = 0; k < n; ++k) {
        for (int i = 0, j = k; j < n; ++i, ++j) {
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;
            
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
    return table[0][n - 1];
}
int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter Elements\n";
    for (int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nUser Collects\t:\t" << getOptimalStrategyOfGame(arr) << "\n";
    return 0;
}
