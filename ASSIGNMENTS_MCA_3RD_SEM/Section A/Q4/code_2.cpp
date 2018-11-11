//
//  q4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 28/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int res(int*x , int *r , int n , int M , int t) {
    int table[M+1];
    table[0] = 0;
    int j = 0;
    for ( int i = 1 ; i <= M; i++) {
        if( j < n) {
            if( x[j] != i) {
                table[i] = table[i-1];
            }
            else {
                if ( i <= t) {
                    table[i] = max(table[i-1] , r[j]);

                }
                else {
                    table[i] = max(r[j] + table[i - t - 1] , table[i-1]);
                }
                j++;
            }
        }
        else {
            table[i] = table[i-1];
        }
    }
    return table[M];
}


int main() {
    int M , n;
    cout << "\nEnter M\t:\t";
    cin >> M;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nEnter Billboards\n";
    for ( int i = 0; i < n; i++ {
      cin >> x[i];
    }
    cout << "\nEnter Revenues\n";
    for ( int i = 0; i < n; i++ {
      cin >> r[i];
    }
    int t;
    cout << "\nEnter t\t:\t";
    cin >> t;
    cout << res( x , r , n , M ,t);
    return 0;
}
