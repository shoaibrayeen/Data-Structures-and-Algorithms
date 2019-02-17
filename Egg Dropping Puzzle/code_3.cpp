//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 Time Complexity : O(n Log k)
*/
int getBinomialCoefficient(int mid , int numberOfEggs , int numberOfFloors) {
    int sum = 0, term = 1;
    for (int i = 1; i <= numberOfEggs && sum < numberOfFloors; ++i) {
        term *= mid - i + 1;
        term /= i;
        sum += term;
    }
    return sum;
}
int getCriticalFloor(int numberOfEggs ,int numberOfFloors) {
    int low = 1, high = numberOfFloors;
    while (low < high) {
        int mid = (low + high) / 2;
        if ( getBinomialCoefficient(mid, numberOfEggs, numberOfFloors) < numberOfFloors) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    
    return low;
}

int main() {
    int numberOfFloors , numberOfEggs;
    cout << "\nEnter Number of Eggs\t:\t";
    cin >> numberOfEggs;
    cout << "\nEnter Number of Floors\t:\t";
    cin >> numberOfFloors;
    cout << "\nCritical Floor\t:\t" << getCriticalFloor(numberOfEggs , numberOfFloors) << "\n";
    return 0;
}
