//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

void findLargestSumPair(vector <int> a) {
    long n = a.size();
    int first , second;
    first = second = INT_MIN;
    for (int i = 0; i < n ; i ++) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        }
        else if (a[i] > second) {
            second = a[i];
        }
    }
    cout << "\nMaximum Sum Pair\t:\t" << first + second ;
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
    findLargestSumPair(a);
    a.clear();
    cout <<  endl;
    return 0;
}
