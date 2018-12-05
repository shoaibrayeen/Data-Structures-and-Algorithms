//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


/*
  Time Complexity  : O(sum*n)
  Space Complexity : O(sum*n)
*/

#include <iostream>
using namespace std;

int isSubsetSum(int set[], int n, int sum) {
    bool subset[sum + 1][n + 1];
    int count[sum + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        subset[0][i] = true;
        count[0][i] = 0;
    }
    for (int i = 1; i <= sum; i++) {
        subset[i][0] = false;
        count[i][0] = -1;
    }
    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            subset[i][j] = subset[i][j - 1];
            count[i][j] = count[i][j - 1];
            if (i >= set[j - 1]) {
                subset[i][j] = subset[i][j] || subset[i - set[j - 1]][j - 1];
                
                if (subset[i][j]) {
                    count[i][j] = max(count[i][j - 1] ,  count[i - set[j - 1]][j - 1] + 1);
                }
            }
        }
    }
    return count[sum][n];
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *arr = new int[n];
    cout << "\nEnter Sorted Array Elements\n";
    for ( int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum;
    cout << "\nEnter Sum\t:\t";
    cin >> sum;
    cout << "\nMaximum Subset Size\t:\t" << isSubsetSum(arr, n, sum) << "\n";
}

