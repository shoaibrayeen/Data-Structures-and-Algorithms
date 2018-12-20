//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


/*
 Time Complexity - O(log n)
*/

#include <iostream>
using namespace std;

void search(int *arr, int low, int high) {
    if ( low > high ) {
        return;
    }
    if ( low == high ) {
        cout << "\nElement is\t:\t" << arr[low] << endl;
        return;
    }
    int mid = (low + high) / 2;
    if ( mid % 2 == 0) {
        if (arr[mid] == arr[mid+1]) {
            search(arr, mid+2, high);
        }
        else {
            search(arr, low, mid);
        }
    }
    else {
        if (arr[mid] == arr[mid-1]) {
            search(arr, mid+1, high);
        }
        else {
            search(arr, low, mid-1);
        }
    }
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
    search(arr, 0 ,n-1);
    return 0;
}
