//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int maximumSum(int arr[], int n, int k) {
    for (int i = 1; i <= k; i++) {
        int min = INT_MAX;
        int index = -1;
        for (int j = 0; j < n; j++ ) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        if (min == 0) {
            break;
        }
        arr[index] = -arr[index];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
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
    int k;
    cout << "\nEnter K\t:\t";
    cin >> k;
    cout << "\nMaximum Sum\t:\t" << maximumSum( a , n , k);
    delete[] a;
    cout <<  endl;
    return 0;
}
