//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<math.h>
using namespace std;
int fib(int n){
    double x = sqrt(5)/5;
    double termOne = x * pow((1+sqrt(5))/2, n);
    double termTwo = -x * pow((1-sqrt(5))/2, n);
    return (int)(termOne + termTwo);
}

int main () {
    cout << "\nEnter Number\t:\t";
    int number;
    cin >> number;
    cout <<"\nThe result is\t:\t" << fib(number);
    cout << endl;
    return 0;
}

