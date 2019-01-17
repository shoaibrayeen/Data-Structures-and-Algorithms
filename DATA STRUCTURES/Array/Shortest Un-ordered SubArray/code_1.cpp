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


bool increasing(vector <int> a) {
    long n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool decreasing(vector <int> a) {
    long n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
        
}

void shortestUnsorted(vector <int> a) {
    if (increasing(a) == true || decreasing(a) == true) {
        cout << "\nShortest Unordered Sub Array is not Present\n";
    }
    else {
        cout << "\nShortest Unordered Sub Array is Present\n";
    }
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
    shortestUnsorted(a);
    a.clear();
    cout <<  endl;
    return 0;
}
