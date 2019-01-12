//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int lbs( int arr[], int n ) {
    int *lis = new int[n];
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int *lds = new int [n];
    for (int i = 0; i < n; i++) {
        lds[i] = 1;
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }
    int max = lis[0] + lds[0] - 1;
    for (int i = 1; i < n; i++) {
        if (lis[i] + lds[i] - 1 > max) {
            max = lis[i] + lds[i] - 1;
        }
    }
    return max;
}


int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *a = new int[n];
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    cout << "\nLength of Sequence\t:\t" << lbs( a , n );
    delete[] a;
    cout <<  endl;
    return 0;
}
