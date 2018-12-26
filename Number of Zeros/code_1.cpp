//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;


int firstZero(int arr[], int low, int high) {
    if (high >= low) {
        int mid = low + (high - low)/2;
        if (( mid == 0 || arr[mid-1] == 1) && arr[mid] == 0) {
            return mid;
        }
        
        if (arr[mid] == 1) {
            return firstZero(arr, (mid + 1), high);
        }
        else {
            return firstZero(arr, low, (mid -1));
        }
    }
    return -1;
}

int countZeroes(int arr[], int n) {
    int first = firstZero(arr, 0, n-1);
    if (first == -1) {
        return 0;
    }
    return (n - first);
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *arr = new int[n];
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nNumber of Zeros\t:\t" << countZeroes(arr , n) << endl;
    delete []arr;
    return 0;
}
