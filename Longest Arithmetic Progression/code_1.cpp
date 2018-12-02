//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int lenghtOfLongestAP(int set[], int n) {
    if (n <= 2) {
        return n;
    }
    int L[n][n];
    int llap = 2;
    for ( int i = 0; i < n; i++) {
        L[i][n-1] = 2;
    }
    for (int j = n-2; j >= 1; j--) {
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1) {
            if (set[i] + set[k] < 2*set[j]) {
                k++;
            }
            else if (set[i] + set[k] > 2*set[j]) {
                L[i][j] = 2;
                i--;
            }
            else {
                L[i][j] = L[j][k] + 1;
                llap = max(llap, L[i][j]);
                i--;
                k++;
            }
        }
        while (i >= 0) {
            L[i][j] = 2;
            i--;
        }
    }
    return llap;
}
int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Sequence\n";
    for(int i =0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nLength of LAP\t:\t" << lenghtOfLongestAP(arr, n) << endl;
    return 0;
}
