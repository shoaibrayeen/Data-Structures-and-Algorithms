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

void toConvert(vector<int>arr) {
    int n = int(arr.size());
    if (n <= 1) {
        return;
    }
    int prev = arr[0];
    arr[0] = arr[0] * arr[1];
    for (int i = 1; i < n - 1; i++) {
        int curr = arr[i];
        arr[i] = prev * arr[i+1];
        prev = curr;
    }
    arr[n-1] = prev * arr[n-1];
    cout << "\nAfter Modification\t:\t";
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter Elements\n";
    for (int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    toConvert(arr);
    return 0;
}
