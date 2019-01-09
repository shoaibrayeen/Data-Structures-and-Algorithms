//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void occurredOnce(int arr[], int n) {
    sort(arr, arr + n);
    if (arr[0] != arr[1]) {
        cout << arr[0] << " ";
    }
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    if (arr[n - 2] != arr[n - 1]) {
        cout << arr[n - 1] << " ";
    }
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
    cout << "\nElements that Occurred Once\t:\t";
    occurredOnce( a , n);
    delete[] a;
    cout <<  endl;
    return 0;
}
