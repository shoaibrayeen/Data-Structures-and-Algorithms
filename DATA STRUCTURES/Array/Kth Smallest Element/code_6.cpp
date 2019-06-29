//
//  code_6.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <set>
using namespace std;

int kthSmallest(int arr[], int n, int k) {
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    auto it = s.begin();
    for (int i = 0; i < k - 1; i++) {
        it++;
    }
    return *it;
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
    int k;
    cout << "Enter K\t:\t";
    cin >> k;
    cout << "\nKth Smallest Element\t:\t" << kthSmallest( a , n , k ) << endl;
    delete[] a;
    return 0;
}
