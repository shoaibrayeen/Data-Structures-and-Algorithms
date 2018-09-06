//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;
int count( int *S, int m, int n )  { 
    int i, j, x, y; 
    int table[n+1][m]; 
    for (i=0; i<m; i++) 
        table[0][i] = 1;  
    for (i = 1; i < n+1; i++) { 
        for (j = 0; j < m; j++) {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0; 
            y = (j >= 1)? table[i][j-1]: 0; 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m-1]; 
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
