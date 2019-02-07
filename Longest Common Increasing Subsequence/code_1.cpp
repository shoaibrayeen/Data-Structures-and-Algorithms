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

void LCIS(vector<int>arr1 , vector<int>arr2) {
    int n = int(arr1.size());
    int m = int(arr2.size());
    int table[m] , parent[m];
    
    for (int j = 0; j < m; j++) {
        table[j] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int current = 0 , last = -1;
        for (int j = 0; j < m; j++) {
            
            if (arr1[i] == arr2[j]) {
                if (current + 1 > table[j]) {
                    table[j] = current + 1;
                    parent[j] = last;
                }
            }
            
            if (arr1[i] > arr2[j]) {
                if (table[j] > current) {
                    current = table[j];
                    last = j;
                }
            }
            
        }
    }
    int result = 0 , index = -1;
    for (int i = 0; i < m; i++) {
        if (table[i] > result) {
            result = table[i];
            index = i;
        }
    }
    int valueLCIS[result];
    for (int i = 0; index != -1; i++) {
        valueLCIS[i] = arr2[index];
        index = parent[index];
    }
    
    cout << "\nLength of LCIS\t:\t " << result;
    cout << "\nLCIS\t:\t";
    for (int i = result - 1; i >= 0; i-- ) {
        cout << valueLCIS[i] << "  ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "\nEnter Size of First Array\t:\t";
    cin >> n;
    vector <int> array1(n);
    cout << "\nEnter Elements of First Array\n";
    for ( int i = 0 ;i < n;i++) {
        cin >> array1[i];
    }
    cout << "\nEnter Size of Second Array\t:\t";
    cin >> n;
    vector <int> array2(n);
    cout << "\nEnter Elements of First Array\n";
    for ( int i = 0 ;i < n;i++) {
        cin >> array2[i];
    }
    LCIS(array1 , array2);
    return 0;
}

