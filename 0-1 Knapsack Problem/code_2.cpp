//
//  code_2.cpp
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
    int K[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i==0 || j==0)
                K[i][j] = 0;
            else if (wt[i-1] <= j)
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }
    return K[n][W];
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

