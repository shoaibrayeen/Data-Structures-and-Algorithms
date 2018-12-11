//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define d 256

int floorSearch(int arr[], int n, int x) {
    if (x >= arr[n-1]) {
        return n-1;
    }
    if (x < arr[0]) {
        return -1;
    }
    for (int i=1; i<n; i++) {
        if (arr[i] > x) {
            return (i-1);
        }
    }
    return -1;
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
    int index = floorSearch(arr, n-1, x);
    if (index == -1) {
        cout << "\nFloor of " << x << " doesn't exist in array\n";
    }
    else {
        cout << "\nFloor of " << x << "\t:\t" << arr[index] << "\n";
    }
    delete []arr;
    return 0;
}
