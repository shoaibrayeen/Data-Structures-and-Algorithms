//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;


int kth(int *arr1, int *arr2, int *end1, int *end2, int k) {
    if (arr1 == end1) {
        return arr2[k];
    }
    if (arr2 == end2) {
        return arr1[k];
    }
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k) {
        if (arr1[mid1] > arr2[mid2]) {
            return kth(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1);
        }
        else {
            return kth(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1);
        }
    }
    else {
        if (arr1[mid1] > arr2[mid2]) {
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        }
        else {
            return kth(arr1, arr2, end1, arr2 + mid2, k);
        }
    }
}


int main() {
    int n1 ,n2;
    cout << "\nEnter Size of 1st array\t:\t";
    cin >> n1;
    int a1[n1];
    cout << "\nEnter 1st Array Elements\n";
    for ( int i = 0; i < n1; i++) {
        cin >> a1[i];
    }
    cout << "\nEnter Size of 2nd array\t:\t";
    cin >> n2;
    int a2[n2];
    cout << "\nEnter 2nd Array Elements\n";
    for ( int i = 0; i < n2; i++) {
        cin >> a2[i];
    }
    int k;
    cout << "\nEnter K\t:\t";
    cin >> k;
    cout << "\nKth Element\t:\t" << kth(a1, a2, a1+n1 , a2 + n2 , k-1) ;
    cout << "\n";
    return 0;
}
