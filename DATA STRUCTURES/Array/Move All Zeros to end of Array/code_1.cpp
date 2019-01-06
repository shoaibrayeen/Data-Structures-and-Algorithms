//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void moveZerosToEnd(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[count++], arr[i]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *a = new int[n];
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    moveZerosToEnd(a, n);
    cout << "\nArray After Moving Zeros\t:\t";
    printArray(a, n);
    return 0;
}
