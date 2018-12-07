//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int diceThrow(int n, int faces, int sum) {
    vector< vector<int> > dp ( n+1 , vector<int> (sum + 1 , 0 ) );
    dp[0][0]=1;
    for(int i = 1; i <= n; i++ ) {
        for(int j = 1; j <= sum; j++) {
            if(j < i) {
                dp[i][j]=0;
            }
            else if ( j > faces*i ) {
                dp[i][j]=0;
            }
            else {
                for( int k = 1; k <= faces && j >= k; k++ ) {
                    dp[i][j]+=dp[i-1][j-k];
                }
            }
            
        }
    }
    return dp[n][sum];
    
}

int main() {
    int n;
    int faces;
    int sum;
    cout << "\nEnter number of dices\t\t\t:\t";
    cin >> n;
    cout << "\nEnter number of faces in a dice\t:\t";
    cin >> faces;
    cout << "\nEnter the value of sum\t\t\t:\t";
    cin >> sum;
    cout<<"\nNumber of ways\t\t\t\t\t:\t" << diceThrow(n,faces,sum);
    cout << endl;
    return 0;
}
