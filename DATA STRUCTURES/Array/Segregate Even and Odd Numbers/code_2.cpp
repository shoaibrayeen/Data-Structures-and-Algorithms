//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrayEvenAndOdd(int arr[], int n) {
    int left = 0, right = n-1;
    while (left < right) {
        while (arr[left]%2 == 0 && left < right) {
            left++;
        }
        while (arr[right]%2 == 1 && left < right) {
            right--;
        }
        if (left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
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
