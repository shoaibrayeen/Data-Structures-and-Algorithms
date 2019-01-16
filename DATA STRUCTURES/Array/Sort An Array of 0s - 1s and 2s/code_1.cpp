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


void sort(vector <int> arr) {
    long n = arr.size();
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count0++;
        }
        if (arr[i] == 1) {
            count1++;
        }
        if (arr[i] == 2) {
            count2++;
        }
    }
    for (int i = 0; i < count0; i++) {
        arr[i] = 0;
    }
    for (int i = count0; i < (count0 + count1); i++) {
        arr[i] = 1;
    }
    for (int i = (count0 + count1); i < n; i++) {
        arr[i] = 2;
    }
    cout << "\nAfter Sorting\t:\t";
    for ( int i  = 0; i < n; i++ ) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    vector<int> a(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    sort(a);
    a.clear();
    cout <<  endl;
    return 0;
}
