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

void toConstructLowerArray(vector<int>arr) {
    int n = int(arr.size());
    vector<int> countSmaller(n);
    for  (int i = 0; i < n; i++) {
        countSmaller[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) {
                countSmaller[i]++;
            }
        }
    }
    cout << "\nElement\t|\tLower Elements on Right Side\n";
    cout << "----------------------------------------\n";
    for ( int i = 0; i < n; i++ ) {
        cout << "\t" << arr[i] << "\t|\t\t" << countSmaller[i] << "\n";
    }
    cout << "\n";
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
    toConstructLowerArray(array);
    return 0;
}

