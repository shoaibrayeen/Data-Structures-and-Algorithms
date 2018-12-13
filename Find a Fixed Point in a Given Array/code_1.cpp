//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int linearSearch(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == i) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Array Elements\n";
    for( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nFixed Point\t:\t" << linearSearch(arr, n) << endl;
    return 0;
}
