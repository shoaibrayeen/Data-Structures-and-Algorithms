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
    if (m == 0) {
      return n; 
    }
    if (n == 0) {
      return m; 
    }
    if (str1[m-1] == str2[n-1]) {
        return editDist(str1, str2, m-1, n-1); 
    }
    return 1 + min ( editDist(str1,  str2, m, n-1),    // Insert 
                     editDist(str1,  str2, m-1, n),   // Remove 
                     editDist(str1,  str2, m-1, n-1) // Replace 
                   ); 
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
