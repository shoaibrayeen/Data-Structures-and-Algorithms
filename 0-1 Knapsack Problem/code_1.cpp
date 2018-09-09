//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

int knapSack(int W, int *wt, int *val, int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n-1] > W)
        return knapSack(W, wt, val, n-1);
    else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                    );
}


int main() {
    int n;
    cout << "\nNumber of items\t:\t";
    cin >> n;
    int val[n] , wt[n];
    for ( int i = 0 ;i < n;i++) {
        cout << "\nEnter weight and its value for " << (i+1) << "\n";
        cin >> wt[i];
        cin >> val[i];
    }
    int w;
    cout << "\nEnter capacity of knapsack\t:\t";
    cin >> w;
    cout << "\nThe Result is\t:\t" << knapSack(w, wt, val, n) << endl;
    return 0;
}
