//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int getCountIncreasingSubArrays(vector<int>arr){
    int n = int(arr.size());
    int count = 0;
    int len = 1;
    for (int i = 0; i < n-1; ++i) {
        if (arr[i + 1] > arr[i]) {
            len++;
        }
        else {
            count += (((len - 1) * len) / 2);
            len = 1;
        }
    }
    if (len > 1) {
        count += (((len - 1) * len) / 2);
    }
    return count;
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
    cout << "\nNumber of Strictly Subarrays\t:\t" << getCountIncreasingSubArrays(array) << "\n";
    return 0;
}
