//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void search(int *arr, int n) {
    int xorValue = arr[0];
    for ( int i = 1; i < n; i++ ) {
        xorValue ^= arr[i];
    }
    cout << "\nElement is\t:\t" << xorValue << endl;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    search(arr, n);
    return 0;
}
