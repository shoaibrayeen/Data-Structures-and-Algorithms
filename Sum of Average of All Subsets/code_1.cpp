//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int nCr(int n, int k) {
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

double resultOfAllSubsets(int arr[], int N) {
    double result = 0.0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    for (int n = 1; n <= N; n++) {
        result += (double)(sum * (nCr(N - 1, n - 1))) / n;
    }
    return result;
}

int main() {
    int n;
    cout << "\nEnter Size of Array\t:\t";
    cin >> n;
    int *arr = new int[n];
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    
    cout << "\nResult\t:\t" << resultOfAllSubsets(arr, n) << endl;
    return 0;
}
