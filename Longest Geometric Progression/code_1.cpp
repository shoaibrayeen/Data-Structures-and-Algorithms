//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int lenOfLongestGP(int set[], int n) {
    if (n < 2) {
        return n;
    }
    if (n == 2) {
        return (set[1] % set[0] == 0);
    }
    sort(set, set+n);
    int L[n][n];
    int llgp = 1;
    
    for (int i = 0; i < n; ++i) {
        if (set[n-1] % set[i] == 0) {
            L[i][n-1] = 2;
        }
        else {
            L[i][n-1] = 1;
        }
    }
    
    for (int j = n - 2; j >= 1; --j) {
        int i = j - 1, k = j+1;
        while (i>=0 && k <= n-1) {
            if (set[i] * set[k] < set[j]*set[j]) {
                ++k;
            }
            else if (set[i] * set[k] > set[j]*set[j]) {
                if (set[j] % set[i] == 0) {
                    L[i][j] = 2;
                }
                else {
                    L[i][j] = 1;
                }
                --i;
            }
            else {
                L[i][j] = L[j][k] + 1;
                if (L[i][j] > llgp) {
                    llgp = L[i][j];
                }
                --i;
                ++k;
            }
        }
        while (i >= 0) {
            if (set[j] % set[i] == 0) {
                L[i][j] = 2;
            }
            else {
                L[i][j] = 1;
            }
            --i;
        }
    }
    return llgp;
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
    cout << "\nLength of LGP\t:\t" << lenOfLongestGP(arr, n) << endl;
    return 0;
}
