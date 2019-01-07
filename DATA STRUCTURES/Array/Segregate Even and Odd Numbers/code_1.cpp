//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void arrayEvenAndOdd(int arr[], int n) {
    
    int i = -1, j = 0;
    while (j != n) {
        if (arr[j] % 2 == 0) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    arrayEvenAndOdd( a , n);
    cout << "\nArray\t:\t";
    print(a,n);
    delete[] a;
    return 0;
}
