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

int getNumberOfIncreasingSubSequence(vector<int>arr) {
    int n = int(arr.size());
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = arr[i] - 1; j >= 0; j--) {
            count[arr[i]] += count[j];
        }
        count[arr[i]]++;
    }
    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += count[i];
    }
    return result;
}

int main() {
    int n;
    cout << "\nEnter Size of Array\t:\t";
    cin >> n;
    vector<int> array(n);
    cout << "\nEnter Array Element\n";
    for (int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nNumber of Increasing Sub-sequence\t:\t" << getNumberOfIncreasingSubSequence(array) << "\n";
    return 0;
}

