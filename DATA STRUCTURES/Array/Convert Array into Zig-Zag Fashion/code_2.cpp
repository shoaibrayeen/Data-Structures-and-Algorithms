//
//  code_2.cpp
//  Algorithms
//
//  Created by Mohd Shoaib Rayeen on 19/03/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;


void zigZag(vector<int> arr) {
    long n = arr.size();
    for (int i=0; i < n; i++) {
        if ((i%2)==0) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        else {
            if (arr[i] < arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
    }
    cout << "\nArray After Modification\t:\t";
    for(int i = 0; i < n; i++ ) {
        cout << arr[i] << "  ";
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
    zigZag(a);
    a.clear();
    cout <<  endl;
    return 0;
}
