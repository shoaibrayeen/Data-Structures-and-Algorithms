//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

/*
  Space Complexity : O(1)
  Time Complexity  : O(n)
  
*/

#include <iostream>
using namespace std;

int maxStolen(int n, int values[]) {
    int dp[3];
    dp[0] = 0;
    dp[1] = values[1];
    
    for(int i = 2; i <= n; i++)  {
        dp[2] = max( dp[1] , dp[0]+values[i] );
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[1];
}


int main() {
    int n;
    cout << "\nEnter the number of houses\t:\t";
    cin >> n;
    int values[n+1];
    cout << "\nEnter the values in the houses\n" << endl;
    for( int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    cout << "\nMaximum stolen value\t:\t" << maxStolen(n, values);
    cout<<endl;
    return 0;
}

