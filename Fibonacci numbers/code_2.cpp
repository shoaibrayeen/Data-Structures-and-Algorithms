//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;
int fib(int n)
{
    int temp[n+2];
    int i;
    temp[0] = 0;
    temp[1] = 1;
    for (i = 2; i <= n; i++) {
        temp[i] = temp[i-1] + temp[i-2];
    }
    
    return temp[n];
}

int main () {
    cout << "\nEnter Number\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << fib(number);
    cout << endl;
    return 0;
}

