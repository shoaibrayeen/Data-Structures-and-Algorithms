//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool myCompare(string X, string Y) {
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1: 0;
}

void printLargest(vector <string> arr) {
    sort(arr.begin(), arr.end(), myCompare);
    cout << "\nLargest Number\t:\t";
    for (int i=0; i < arr.size() ; i++ ) {
        cout << arr[i];
    }
    cout << "\n";
}


int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    vector<string> a(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    printLargest(a);
    a.clear();
    cout <<  endl;
    return 0;
}
