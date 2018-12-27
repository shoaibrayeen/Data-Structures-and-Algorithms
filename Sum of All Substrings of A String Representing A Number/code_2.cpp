//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int sumOfSubstrings(string num) {
    long n = num.length();
    int sumofdigit[2];
    sumofdigit[0] = num[0] - '0';
    int res = sumofdigit[0];
    for (int i = 1; i < n; i++ ) {
        int numi = num[i] - '0';
        sumofdigit[1] = (i+1) * numi + 10 * sumofdigit[0];
        res += sumofdigit[1];
        sumofdigit[0] = sumofdigit[1];
    }
    return res;
}

int main() {
    string str;
    cout << "\nEnter Number\t:\t";
    getline(cin , str);
    cout << "\nTotal Sum\t\t:\t" << sumOfSubstrings(str) << endl;
    return 0;
}
