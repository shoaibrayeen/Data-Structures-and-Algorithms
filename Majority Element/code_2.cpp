//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void findMajority(int arr[], int n) {
    int maxCount = 0;
    int index = -1; // sentinels
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            index = i;
        }
    }
    if (maxCount > n/2) {
        cout << "\n " << " Majority Element\t:\t" << arr[index] << endl;
    }
    else {
        cout << "\nNo Majority Element" << endl;
    }
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Array Elements\n";
    for( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    findMajority(arr,n);
    return 0;
}
