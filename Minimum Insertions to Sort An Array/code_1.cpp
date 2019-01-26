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

int getMinInsertionStepToSortArray(vector<int>arr) {
    int n = int(arr.size());
    int lis[n];
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }
    return (n - max);
}


int main() {
    cout << "\nEnter Size\t:\t";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nMinimum Insertions\t:\t" << getMinInsertionStepToSortArray(arr) << "\n";
    arr.clear();
    return 0;
}
