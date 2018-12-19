//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int countRotations(int arr[], int n) {
    int min = arr[0];
    int min_index = -1;
    for (int i=0; i<n; i++) {
        if (min > arr[i]) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
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
    cout << "\nRotation Count\t:\t" <<  countRotations(arr, n) << endl;
    return 0;
}
