//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<string.h>
using namespace std;

int editDist(string str1 , string str2 , int m ,int n) { 
    int table[m+1][n+1];
    for(int i = 0 ; i <= m; i++ ) {
        for(int j = 0; j <= n; j++ ) {
            if ( i == 0 ) {
                table[i][j] = j;
            }
            if ( j == 0 ) {
                table[i][j] = i;
            }
            if ( str1[i-1] == str2[i-1] ) {
                table[i][j] = table[i-1][j-1];
            }
            else {
                table[i][j] = 1 + min(table[i][j-1] , table[i-1][j] , table[i-1][j-1]);
            }
        }
    }
    return table[m][n];
}

int main() {
    string s1 , s2;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\nEdit Distance\t:\t" << editDist( s1, s2 , s1.length(), s2.length() ) << endl;
    return 0;
}
