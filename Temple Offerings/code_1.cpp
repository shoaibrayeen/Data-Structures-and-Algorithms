//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;


int offeringNumber(vector <int> templeHeight) {
    long n = templeHeight.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int left = 0, right = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (templeHeight[j] < templeHeight[j + 1]) {
                ++left;
            }
            else {
                break;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (templeHeight[j] < templeHeight[j - 1]) {
                ++right;
            }
            else {
                break;
            }
        }
        sum += max(right, left) + 1;
    }
    
    return sum;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nTotal Offerings\t:\t" << offeringNumber(arr);
    arr.clear();
    cout <<  endl;
    return 0;
}
