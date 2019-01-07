//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void segregate0and1(int arr[], int n) {
    int first = 0;
    int second = n - 1;
    while(first < second) {
        if(arr[first] == 1) {
            swap(arr[first], arr[second]);
            second--;
        }
        else {
            first++;
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
    segregate0and1( a , n);
    cout << "\nArray\t:\t";
    print(a,n);
    delete[] a;
    return 0;
}
