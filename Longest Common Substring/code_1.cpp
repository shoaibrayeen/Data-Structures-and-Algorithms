//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int lcs( string s1 , string s2, long m, long n , int count) {
    
    if (m == 0 || n == 0) {
        return count;
    }
    if (s1[m-1] == s2[n-1]) {
        count = lcs(s1 , s2 , m - 1, n - 1, count + 1);
    }
    count = max(count, max(lcs(s1 , s2 ,  m , n - 1, 0), lcs( s1 , s2 ,  m - 1,  n , 0)));
    return count;
}

int main() {
    string s1 , s2;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\nLength of substring\t:\t " << lcs( s1, s2 , s1.length(), s2.length() , 0 ) << "\n";
    
    return 0;
}
