//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

/*
  Index Starting from 0!
  0 , 2 , 4 , 6 , ... -> Positive Numbers
  1 , 3 , 5 , 7 , ... -> Negative Numbers
*/

#include <iostream>
using namespace std;

void rearrange(int a[], int n) {
    cout << "\nArray Before Modification\t:\t";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    int positive = 0, negative = 1;
    while (true) {
        while (positive < n && a[positive] >= 0) {
            positive += 2;
        }
        while (negative < n && a[negative] <= 0) {
            negative += 2;
        }
        if (positive < n && negative < n) {
            swap(a[positive], a[negative]);
        }
        else {
            break;
        }
    }
    cout << "\nArray After Modification\t:\t";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
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
    rearrange( a , n);
    delete[] a;
    cout <<  endl;
    return 0;
}
