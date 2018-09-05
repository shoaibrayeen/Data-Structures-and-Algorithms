//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

int count( int *S , int m , int n ) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m <=0 && n >= 1)
        return 0;
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
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
