//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int minJumps(int arr[], int l, int h) {
    if (h == l) {
        return 0;
    }
    if (arr[l] == 0) {
        return INT_MAX;
    }
    int min = INT_MAX;
    for (int i = l + 1; i <= h && i <= l + arr[l]; i++) {
        int jumps = minJumps(arr, i, h);
        if(jumps != INT_MAX && jumps + 1 < min) {
            min = jumps + 1;
        }
    }
    
    return min;
}


int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int array[n];
    cout << "\nEnter Array Elements\n";
    for ( int i = 0 ;i < n;i++) {
        cin >> array[i];
    }
    cout << "\nMinimum Jumps\t:\t" << minJumps(array, 0, n-1) << "\n";
    return 0;
}
