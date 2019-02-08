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

int knapSack(int W, vector<int> wt, vector<int>val) {
    int n = int(wt.size());
    int dp[W+1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j < n; j++) {
            if (wt[j] <= i) {
                dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
            }
        }
    }
    return dp[W];
}


int main() {
    int n;
    cout << "\nNumber of items\t:\t";
    cin >> n;
    vector <int> val(n) , wt(n);
    for ( int i = 0 ;i < n;i++) {
        cout << "\nEnter weight and its value for " << (i+1) << "\n";
        cin >> wt[i];
        cin >> val[i];
    }
    int w;
    cout << "\nEnter capacity of knapsack\t:\t";
    cin >> w;
    cout << "\nThe Result is\t:\t" << knapSack(w, wt, val) << endl;
    return 0;
}
