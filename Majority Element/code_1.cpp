//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

bool isMajority(int arr[], int n, int x) {
    int last_index = n%2? (n/2+1): (n/2);
    for (int i = 0; i < last_index; i++) {
        if (arr[i] == x && arr[i+n/2] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Array Elements\n";
    for( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    int maj;
    cout << "\nEnter Majority Element\t:\t";
    cin >> maj;
    if (isMajority(arr, n, maj) ) {
        cout << "   " << maj << " apprears more than n/2 times in Array\n";
    }
    else {
        cout << "  " << maj << " does not apprear more than n/2 times in Array\n";
    }
    return 0;
}
