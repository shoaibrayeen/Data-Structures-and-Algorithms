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


void largestThree(vector <int> a) {
    sort(a.begin() , a.end() , greater<int>());
    cout << "\nLargest Three Elements\t:\t";
    for ( int i  = 0; i < 3; i++ ) {
        cout << a[i] << "  ";
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
    largestThree(a);
    a.clear();
    cout <<  endl;
    return 0;
}
