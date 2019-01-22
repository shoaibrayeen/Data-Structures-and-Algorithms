//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;

struct Temple
{
    int L;
    int R;
};

int offeringNumber(vector <int> templeHeight) {
    long n = templeHeight.size();
    Temple chainSize[n];
    for (int i = 0; i < n; ++i) {
        chainSize[i].L = -1;
        chainSize[i].R = -1;
    }
    chainSize[0].L = 1;
    chainSize[n-1].R = 1;
    for (int i = 1; i < n; ++i ) {
        if (templeHeight[i - 1] < templeHeight[i]) {
            chainSize[i].L = chainSize[i - 1].L + 1;
        }
        else {
            chainSize[i].L = 1;
        }
    }
    for (int i = n-2; i >= 0; --i ) {
        if (templeHeight[i + 1] < templeHeight[i]) {
            chainSize[i].R = chainSize[i + 1].R + 1;
        }
        else {
            chainSize[i].R = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += max(chainSize[i].L, chainSize[i].R);
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
