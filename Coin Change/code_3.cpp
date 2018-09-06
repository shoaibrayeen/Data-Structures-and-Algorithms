//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
int count( int *S, int m, int n )  { 
    int table[n+1];  
    memset(table, 0, sizeof(table)); 
    table[0] = 1;
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
} 
int main () {
    int number_coin;
    cout << "\nNumber of Coins\t:\t";
    cin >> number_coin;
    int array[number_coin];
    cout << "\nEnter Coins\n";
    for( int i = 0; i < number_coin; ++i ) {
        cin >> array[i];
    }
    cout << "\nValue for Coin Change\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << count(array , number_coin , number );
    cout << endl;
    return 0;
}
