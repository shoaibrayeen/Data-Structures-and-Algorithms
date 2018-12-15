//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int findCandidate(int a[], int size) {
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (a[maj_index] == a[i]) {
            count++;
        }
        else {
            count--;
        }
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

bool isMajority(int a[], int size, int cand) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == cand) {
            count++;
        }
    }
    
    if (count > size/2) {
        return 1;
    }
    else {
        return 0;
    }
}

void printMajority(int a[], int size) {
    int cand = findCandidate(a, size);
    if (isMajority(a, size, cand)) {
        cout << "\n Majority Element\t:\t" << cand << "\n";
    }
    else {
        cout << "\nNo Majority Element\n";
    }
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
    printMajority(arr,n);
    return 0;
}
