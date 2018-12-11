//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define d 256

int floorSearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }
    if (x >= arr[high]) {
        return high;
    }
    int mid = (low+high)/2;
    if (arr[mid] == x) {
        return mid;
    }
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid]) {
        return mid-1;
    }
    if (x < arr[mid]) {
        return floorSearch(arr, low, mid-1, x);
    }
    return floorSearch(arr, mid+1, high, x);
}

int main() {
    cout << "\nEnter Size\t:\t";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Sorted Array\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nEnter Value to find floor\t:\t";
    int x;
    cin >> x;
    int index = floorSearch(arr, 0 ,n-1, x);
    if (index == -1) {
        cout << "\nFloor of " << x << " doesn't exist in array\n";
    }
    else {
        cout << "\nFloor of " << x << "\t:\t" << arr[index] << "\n";
    }
    delete []arr;
    return 0;
}
