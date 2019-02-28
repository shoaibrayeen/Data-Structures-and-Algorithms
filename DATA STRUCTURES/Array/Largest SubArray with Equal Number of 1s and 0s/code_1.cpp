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

void findSubArray(vector<int>arr) {
    int n = int(arr.size());
    int sum = 0;
    int maxSize = -1, startindex = 0;
    for (int i = 0; i < n-1; i++) {
        sum = (arr[i] == 0)? -1 : 1;
        
        for (int j = i+1; j < n; j++) {
            (arr[j] == 0)? (sum += -1): (sum += 1);
            
            if (sum == 0 && maxSize < j-i+1) {
                maxSize = j - i + 1;
                startindex = i;
            }
        }
    }
    if (maxSize == -1) {
        cout << "\nNo such subarray\n";
    }
    else {
        int lastIndex = startindex + maxSize - 1;
        cout << "\nStart From\t:\t" << startindex << "\nEnd at\t\t:\t" << lastIndex;
        cout << "\nLargest SubArray\t:\t";
        for ( int i = startindex; i <= lastIndex; i++ ) {
            cout << arr[i] << "  ";
        }
        cout << "\n";
    }
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
    findSubArray(array);
    return 0;
}

