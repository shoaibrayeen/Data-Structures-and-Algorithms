//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int countRotations(int arr[], int low, int high) {
    if (high < low) {
        return 0;
    }
    if (high == low) {
        return low;
    }
    int mid = (high + low)/2;
    if (mid < high && arr[mid+1] < arr[mid]) {
        return (mid+1);
    }
    if (mid > low && arr[mid] < arr[mid - 1]) {
        return mid;
    }
    if (arr[high] > arr[mid]) {
        return countRotations(arr, low, mid-1);
    }
    return countRotations(arr, mid+1, high);
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
    cout << "\nRotation Count\t:\t" <<  countRotations(arr, 0 ,n-1) << endl;
    return 0;
}
