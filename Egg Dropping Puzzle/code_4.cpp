//
//  code_4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int getCriticalFloor(int numberOfEggs ,int numberOfFloors) {
    int dp[2][numberOfFloors + 1];
    dp[0][1] = 1;
    dp[1][0] = 0;
    for ( int i = 0; i <= numberOfFloors; i++ ) {
        dp[1][i] = i;
    }
    for ( int i = 2; i <= numberOfEggs; i++ ) {
        for (int j = 2; j <= numberOfFloors; j++ ) {
            dp[i%2][j] = INT_MAX;
            int temp;
            for ( int k = 1; k <= j; k++ ) {
                temp = 1 + max( dp[(i-1)%2][k-1] , dp[i%2][j-k]);
                if ( temp < dp[i%2][j] ) {
                    dp[i%2][j] = temp;
                }
            }
        }
    }
    return dp[numberOfEggs%2][numberOfFloors];
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
