//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int findMinRec(int arr[], int i, int sumCalculated, int sumTotal) {
    if ( i == 0 ) {
        return abs((sumTotal-sumCalculated) - sumCalculated);
    }
    return min(findMinRec( arr, i-1, sumCalculated+arr[i-1], sumTotal), findMinRec(arr, i-1, sumCalculated, sumTotal) );
}


int findMin(int arr[], int n) {
    int sumTotal = 0;
    for (int i=0; i<n; i++) {
        sumTotal += arr[i];
    }
    return findMinRec(arr, n, 0, sumTotal);
}


int main() {
    cout << "\nEnter Size\t:\t";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "\nEnter Array Elements\n";
    for ( int i  = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nMinimum difference\t:\t" << findMin(arr, n) << endl;
    return 0;
}
