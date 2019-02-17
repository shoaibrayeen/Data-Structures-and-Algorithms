//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int getCriticalFloor(int numberOfEggs ,int numberOfFloors) {
    if ( numberOfFloors == 1 || numberOfFloors == 0 ) {
        return numberOfFloors;
    }
    if ( numberOfEggs == 1 ) {
        return numberOfFloors;
    }
    int temp , result = INT_MAX;
    for ( int i = 1; i <= numberOfFloors; i++ ) {
        temp = max ( getCriticalFloor(numberOfEggs - 1, i - 1) , getCriticalFloor(numberOfEggs, numberOfFloors - i));
        if ( temp < result ) {
            result = temp;
        }
    }
    return result + 1;
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
