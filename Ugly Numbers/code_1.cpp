
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

// CPP program to find nth ugly number
#include<iostream>
using namespace std;
int maxDivide(int a, int b) {
    while (a%b == 0) {
        a = a/b;
    }
    return a;
}

int isUgly(int num) {
    num = maxDivide(num, 2);
    num = maxDivide(num, 3);
    num = maxDivide(num, 5);
    
    return (num == 1)? 1 : 0;
}
int getNthUglyNo(int n) {
    int i = 1;
    int count = 1;
    while (n > count) {
        i++;
        if (isUgly(i))
            count++;
    }
    return i;
}
int main() {
    cout << "\nEnter Number\t:\t";
    unsigned int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << getNthUglyNo(number);
    cout << endl;
    return 0;
}
