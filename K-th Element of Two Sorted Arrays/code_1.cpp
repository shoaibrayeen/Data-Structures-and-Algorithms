//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;


int kth(int arr1[], int arr2[], int m, int n, int k) {
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            sorted1[d++] = arr1[i++];
        }
        else {
            sorted1[d++] = arr2[j++];
        }
    }
    while (i < m) {
        sorted1[d++] = arr1[i++];
    }
    while (j < n) {
        sorted1[d++] = arr2[j++];
    }
    return sorted1[k - 1];
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
    cout << "\nKth Element\t:\t" << kth(a1, a2, n1 , n2 , k) ;
    cout << "\n";
    return 0;
}
