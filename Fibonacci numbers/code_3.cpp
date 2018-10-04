//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

int fib(int num) {
    int prev  = 0 , res = 1 , next;;
    if( num <= 0) {
        return 0;
    }
    for (int i = 2; i <= num; i++) {
        next = prev + res;
        prev = res;
        res = next;
    }
    return res;
}

int main () {
    cout << "\nEnter Number\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << fib(number);
    cout << endl;
    return 0;
}

