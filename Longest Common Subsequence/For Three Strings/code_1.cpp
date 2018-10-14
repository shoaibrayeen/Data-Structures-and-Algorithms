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

int lcs( string s1 , string s2, string s3 ,  long m, long n , long o) {
    if (m == 0 || n == 0 || o == 0 ) {
        return 0;
    }
    if (s1[m-1] == s2[n-1] && s1[m-1] == s3[o-1]) {
        return 1 + lcs(s1, s2, s3 , m-1, n-1 ,o-1);
    }
    else {
        return max ( max(lcs(s1, s2, s3 ,  m, n-1 , o), lcs(s1, s2, m-1, n , o)) , lcs( s1 , s2 , s3 , m , n , k-1) );
    }
}

int main() {
    string s1 , s2 , s3;;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\n3rd String\t:\t";
    cin >> s3;
    cout << "\nLength of LCS\t:\t" << lcs( s1, s2 , s3 , s1.length(), s2.length() ,  s3.length() ) << endl;
    return 0;
}
