//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void segregate0and1(int arr[], int n) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        arr[i] = 0;
    }
    for (int i = count; i < n; i++) {
        arr[i] = 1;
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
