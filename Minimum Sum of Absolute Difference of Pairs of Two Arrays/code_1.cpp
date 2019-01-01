//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int MinSum(int a[], int b[], int n) {
    sort(a, a+n);
    sort(b, b+n);
    int sum = 0 ;
    for (int i = 0; i < n; i++ ) {
        sum = sum + abs(a[i]-b[i]);
    }
    return sum;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    cout << "\nEnter First Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    cout << "\nEnter Second Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> b[i];
    }
    cout << "Minimum Sum\t:\t" << MinSum(a, b, n) << endl;
    return 0;
}
