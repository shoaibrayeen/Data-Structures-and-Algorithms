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


unsigned long getMissingNo (vector<int> a) {
    unsigned long n = a.size();
    unsigned long total  = (n+1)*(n+2)/2;
    for (int i = 0; i< n; i++) {
        total -= a[i];
    }
    return total;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    vector <int> a(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    cout << "\nMissing Number\t:\t" << getMissingNo(a);
    a.clear();
    cout <<  endl;
    return 0;
}
