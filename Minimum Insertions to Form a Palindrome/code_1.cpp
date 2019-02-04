//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

int getLengthOfMinInsertions(string str, int l, int h) {
    if (l > h) {
        return INT_MAX;
    }
    if (l == h) {
        return 0;
        
    }
    if (l == h - 1) {
        return (str[l] == str[h])? 0 : 1;
    }
    return (str[l] == str[h])? getLengthOfMinInsertions(str, l + 1, h - 1): (  min (
        getLengthOfMinInsertions(str, l, h - 1), getLengthOfMinInsertions(str, l + 1, h)
                                                                                 ) + 1);
}

int main() {
    string str;
    cout << "\nEnter String\t:\t";
    cin >> str;
    cout << "\nMinimum Insertions to form Palindrome\t:\t" << getLengthOfMinInsertions(str, 0, int(str.length())-1) << "\n";
    return 0;
}
