//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int findPeakUtil(int arr[], int low, int high, int n) {
    int mid = low + (high - low)/2;
    if ((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])) {
        return mid;
    }
    else if (mid > 0 && arr[mid-1] > arr[mid]) {
        return findPeakUtil(arr, low, (mid -1), n);
    }
    else return findPeakUtil(arr, (mid + 1), high, n);
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
    cout << "\nIndex of a peak point\t:\t" << findPeakUtil(arr,0 , n-1 , n) << endl;
    return 0;
}
