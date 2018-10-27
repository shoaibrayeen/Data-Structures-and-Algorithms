//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
//This will be done using bottom-up approach
#include<iostream>
using namespace std;
int fib(int num) {
    int temp[num+2];
    int i;
    temp[0] = 0;
    temp[1] = 1;
    for (i = 2; i <= num; i++) {
        temp[i] = temp[i-1] + temp[i-2];
    }
    
    return temp[num];
}

int main () {
    cout << "\nEnter Number\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << fib(number);
    cout << endl;
    return 0;
}

