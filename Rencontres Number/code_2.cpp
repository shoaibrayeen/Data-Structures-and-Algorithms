//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <bits/stdc++.h> 
using namespace std; 

int C[n+1][m+1] , n , m; 
int binomialCoeff() { 
    int i, j; 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, m); j++) { 
            if (j == 0 || j == i) {
                C[i][j] = 1; 
            }
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j]; 
            }
        } 
    } 
  
    return C[n][m]; 
}

int RencontresNumber() { 
    int dp[n+1][m+1] = { 0 }; 
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= m; j++) { 
            if (j <= i) { 
                if (i == 0 && j == 0) {
                    dp[i][j] = 1; 
                }
                else if (i == 1 && j == 0) {
                    dp[i][j] = 0; 
                }
                else if (j == 0) {
                    dp[i][j] = (i - 1) * (dp[i - 1][0] + dp[i - 2][0]); 
                }
                else {
                    dp[i][j] = C[i][j] * dp[i - j][0]; 
                }
            } 
        } 
    } 
  
    return dp[n][m]; 
}  
  
int main() { 
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nEnter m\t:\t";
    cin >> m;
    cout << "\nResult\t:\t" << RencontresNumber() << endl; 
    return 0; 
} 
