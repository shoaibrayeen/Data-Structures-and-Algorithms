//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void pushZerosToEnd(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[count++], arr[i]);
        }
    }
}

void modifyAndRearrangeArr(int arr[], int n) {
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] != 0) && (arr[i] == arr[i + 1])) {
            arr[i] = 2 * arr[i];
            arr[i + 1] = 0;
            i++;
        }
    }
    pushZerosToEnd(arr, n);
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
    cout << "\nEnter First Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    modifyAndRearrangeArr(a, n);
    cout << "\nArray After Moving Zeros\t:\t";
    printArray(a, n);
    delete[] a;
    return 0;
}
