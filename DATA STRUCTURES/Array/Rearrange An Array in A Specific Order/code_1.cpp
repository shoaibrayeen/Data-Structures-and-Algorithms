//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void rearrangeArray(int arr[], int n) {
    sort(arr, arr + n);
    int temp[n];
    int tIndex = 0;
    for (int i = 0, j = n-1; i <= n / 2 || j > n / 2; i++, j--) {
        temp[tIndex] = arr[i];
        tIndex++;
        temp[tIndex] = arr[j];
        tIndex++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    cout << "\nArray After Modification\t:\t";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout <<  endl;
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
    rearrangeArray( a , n );
    delete[] a;
    cout <<  endl;
    return 0;
}
