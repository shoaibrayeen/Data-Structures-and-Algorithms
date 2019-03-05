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

void printNextGreaterElement(vector<int> arr) {
    int n = int(arr.size());
    int next , temp;
    cout << "\nElement\t|\tNGE\n";
    cout << "------------------\n";
    for (int i = 0; i < n; i++) {
        next = -1;
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
            
        }
        cout << "\t" << arr[i] << "\t|\t " << next << endl;
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
    printNextGreaterElement(array);
    return 0;
}

