//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;


void largestThree(vector <int> a) {
    long n = a.size();
    int first , second, third;
    third = first = second = INT_MIN;
    for (int i = 0; i < n ; i ++) {
        if (a[i] > first) {
            third = second;
            second = first;
            first = a[i];
        }
        else if (a[i] > second) {
            third = second;
            second = a[i];
        }
        else if (a[i] > third) {
            third = a[i];
        }
    }
    cout << "\nLargest Three Elements\t:\t" << first << " " << second << " " << third;
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
