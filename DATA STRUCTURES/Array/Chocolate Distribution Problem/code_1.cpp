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


int getMinDiff(vector<int>arr , int m) {
    long n = arr.size();
    if (m==0 || n==0) {
        return 0;
    }
    sort(arr.begin(), arr.end());
    if (n < m) {
        return -1;
    }
    int min_diff = INT_MAX;
    int first = 0, last = 0;
    for (int i = 0; i + m - 1 < n; i++ ) {
        int diff = arr[i+m-1] - arr[i];
        if (diff < min_diff) {
            min_diff = diff;
            first = i;
            last = i + m - 1;
        }
    }
    return (arr[last] - arr[first]);
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int m;
    vector<int> arr(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nEnter m\t:\t";
    cin >> m;
    cout << "\nMinimum Difference\t:\t" << getMinDiff(arr, m);
    arr.clear();
    cout <<  endl;
    return 0;
}
