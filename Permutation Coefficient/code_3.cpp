//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;

int permutationCoeff(int n, int k) { 
    int res = 1;
    while ( k > 0 ) {
      res *= n;
      --n;
      --k;
    }
    return res;
} 
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int number;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout <<"\nThe result is\t:\t" << permutationCoeff(n,k);
    cout << endl;
    return 0;
}
