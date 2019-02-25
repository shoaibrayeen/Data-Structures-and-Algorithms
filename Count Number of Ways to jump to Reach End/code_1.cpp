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

void countWaysToJump(vector<int>arr) {
    int n = int(arr.size());
    int count_jump[n];
    memset(count_jump, 0, sizeof(count_jump));
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] >= n - i - 1) {
            count_jump[i]++;
        }
        for (int j = i+1; j < n-1 && j <= arr[i] + i; j++) {
            if (count_jump[j] != -1) {
                count_jump[i] += count_jump[j];
            }
        }
        if (count_jump[i] == 0) {
            count_jump[i] = -1;
        }
    }
    cout << "\nCount Array\t:\t";
    for (int i = 0; i < n; i++) {
        cout << count_jump[i] << " ";
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
    countWaysToJump(array);
    return 0;
}

