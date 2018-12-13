//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high) {
    if(high >= low) {
        int mid = (low + high)/2;
        if(mid == arr[mid]) {
            return mid;
        }
        if(mid > arr[mid]) {
            return binarySearch(arr, (mid + 1), high);
        }
        else {
            return binarySearch(arr, low, (mid -1));
        }
    }
    return -1;
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
    cout << "\nFixed Point\t:\t" << binarySearch(arr ,0 , n-1) << endl;
    return 0;
}
