//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int minJumps(int arr[], int n) {
    int *jumps = new int[n];
    int min;
    jumps[n-1] = 0;
    for (int i = n-2; i >=0; i--) {
        if (arr[i] == 0) {
            jumps[i] = INT_MAX;
        }
        else if (arr[i] >= n - i - 1) {
            jumps[i] = 1;
        }
        else {
            min = INT_MAX;
            for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
                if (min > jumps[j]) {
                    min = jumps[j];
                }
            }
            if (min != INT_MAX) {
                jumps[i] = min + 1;
            }
            else {
                jumps[i] = min;
            }
        }
    }
    
    return jumps[0];
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
