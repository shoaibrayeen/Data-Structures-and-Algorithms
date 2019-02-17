//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Time Complexity: O(nk^2)
 Auxiliary Space: O(nk)
*/

int getCriticalFloor(int numberOfEggs ,int numberOfFloors) {
    int dp[numberOfEggs + 1][numberOfFloors + 1];
    for ( int i = 1; i <= numberOfEggs; i++ ) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for ( int i = 0; i <= numberOfFloors; i++ ) {
        dp[1][i] = i;
    }
    for ( int i = 2; i <= numberOfEggs; i++ ) {
        for (int j = 2; j <= numberOfFloors; j++ ) {
            dp[i][j] = INT_MAX;
            int temp;
            for ( int k = 1; k <= j; k++ ) {
                temp = 1 + max( dp[i-1][k-1] , dp[i][j-k]);
                if ( temp < dp[i][j] ) {
                    dp[i][j] = temp;
                }
            }
        }
    }
    return dp[numberOfEggs][numberOfFloors];
}

int main() {
    int numberOfFloors , numberOfEggs;
    cout << "\nEnter Number of Eggs\t:\t";
    cin >> numberOfEggs;
    cout << "\nEnter Number of Floors\t:\t";
    cin >> numberOfFloors;
    cout << "\nCritical Floor\t:\t" << getCriticalFloor(numberOfEggs , numberOfFloors) << "\n";
    return 0;
}
