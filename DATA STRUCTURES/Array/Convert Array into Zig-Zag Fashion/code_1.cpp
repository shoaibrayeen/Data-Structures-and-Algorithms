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


void zigZag(vector<int> arr) {
    long n = arr.size();
    bool flag = true;
    for (int i=0; i <= n-2; i++) {
        if (flag) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        else {
            if (arr[i] < arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        flag = !flag;
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
