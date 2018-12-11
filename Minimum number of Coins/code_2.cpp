//
//  test.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

/*
 coin should be in sorted increasing order
*/

#include <iostream>
using namespace std;

int floorSearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }
    if (x >= arr[high]) {
        return high;
    }
    int mid = (low+high)/2;
    if (arr[mid] == x) {
        return mid;
    }
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid]) {
        return mid-1;
    }
    if (x < arr[mid]) {
        return floorSearch(arr, low, mid-1, x);
    }
    return floorSearch(arr, mid+1, high, x);
}

void minCoin(int* arr , int n , int value) {
    int count = 0;
    cout << "\nCoins\t\t\t\t\t:\t";
    while ( value > 0 ) {
        int temp = arr[floorSearch(arr, 0 ,n, value)];
        cout << temp << "\t";
        value -= temp;
        count ++;
    }
    cout << "\nMinimum Number of Coins\t:\t" << count;
}
int main() {
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200 , 500, 1000 , 2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nEnter Value to find minimum number of coins\t:\t";
    int x;
    cin >> x;
    minCoin(arr , n-1 , x);
    cout << endl;
    return 0;
}
