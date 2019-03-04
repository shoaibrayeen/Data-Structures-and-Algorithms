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

void printKMax(vector<int> arr , int k) {
    int n = int(arr.size());
    int include;
    cout << "\nMaximum Subarray\t:\t";
    for (int i = 0; i <= n-k; i++) {
        include = arr[i];
         for (int j = 1; j < k; j++) {
            if (arr[i+j] > include) {
                include = arr[i+j];
            }
        }
        cout << include << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "\nEnter Size of Array\t:\t";
    cin >> n;
    vector<int> array(n);
    cout << "\nEnter Array Element\n";
    for (int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nEnter K\t:\t";
    cin >> n;
    printKMax(array, n);
    return 0;
}

