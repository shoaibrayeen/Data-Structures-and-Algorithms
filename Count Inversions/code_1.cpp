//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

int countInversion(vector<int> arr) {
    long n = arr.size();
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }
    return inv_count;
}

int main(int argv, char** args) {
    int n;
    cout << "\nEnter Number of Element\t:\t";
    cin >> n;
    cout << "\nEnter Elements\n";
    vector<int> arr(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nNumber of Inversions\t:\t" << countInversion(arr) << endl;
    return 0;
}
