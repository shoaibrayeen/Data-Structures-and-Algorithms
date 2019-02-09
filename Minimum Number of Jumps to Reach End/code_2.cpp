//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int minJumps(int arr[], int n) {
    int *jumps = new int[n];
    if (n == 0 || arr[0] == 0) {
        return INT_MAX;
    }
    jumps[0] = 0;
    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n-1];
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
    cout << "\nMinimum Jumps\t:\t" << minJumps(array, n) << "\n";
    return 0;
}
