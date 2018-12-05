//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int getClosest(int, int, int);
int findClosest(int arr[], int n, int target) {
    if (target <= arr[0]) {
        return arr[0];
    }
    if (target >= arr[n - 1]) {
        return arr[n - 1];
    }
    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        }
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1]) {
                return getClosest(arr[mid - 1], arr[mid], target);
            }
            j = mid;
        }
        else {
            if (mid < n - 1 && target < arr[mid + 1]) {
                return getClosest(arr[mid],arr[mid + 1], target);
            }
            i = mid + 1;
        }
    }
    return arr[mid];
}


int getClosest(int val1, int val2, int target) {
    if (target - val1 >= val2 - target) {
        return val2;
    }
    else {
        return val1;
    }
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *arr = new int[n];
    cout << "\nEnter Sorted Array\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    int target;
    cout << "\nEnter Number\t:\t";
    cin >> target;
    cout << "\nClosest Number\t:\t " << findClosest(arr, n, target) << "\n";
}
