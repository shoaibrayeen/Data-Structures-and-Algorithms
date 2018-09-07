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

int lcs( string s1 , string s2, long m, long n ) {
    if (m == 0 || n == 0)
        return 0;
    if (s1[m-1] == s2[n-1])
        return 1 + lcs(s1, s2, m-1, n-1);
    else
        return max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n));
}

int main() {
    string s1 , s2;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\nLength of LCS\t:\t" << lcs( s1, s2 , s1.length(), s2.length() ) << endl;
    return 0;
}

