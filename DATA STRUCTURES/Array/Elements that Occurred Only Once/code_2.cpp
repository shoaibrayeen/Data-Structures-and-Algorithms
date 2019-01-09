//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <unordered_map>
using namespace std;

void occurredOnce(int arr[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == 1) {
            cout << it->first << " ";
        }
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
    cout << "\nElement that appeared once\t:\t";
    occurredOnce( a , n);
    delete[] a;
    cout <<  endl;
    return 0;
}
