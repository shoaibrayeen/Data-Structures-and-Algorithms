//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int getBitonicPoint(vector<int> array , int left , int right ) {
    if ( left <= right ) {
        int mid = ( left + right ) / 2;
        if (array[mid-1] < array[mid] && array[mid] > array[mid+1]) {
            return mid;
        }
        if (array[mid] < array[mid+1]) {
            return getBitonicPoint(array, mid + 1 , right);
        }
        else {
            return getBitonicPoint(array, left, mid - 1);
        }
    }
    return -1;
}

int main() {
    cout << "\nEnter Size of Array\t:\t";
    int n ;
    cin >> n;
    vector<int> array(n);
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nBitonic Point Element\t:\t" << array[getBitonicPoint(array, 0, n-1)] << "\n";
    return 0;
}


