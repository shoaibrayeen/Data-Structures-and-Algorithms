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

int maxSubarrayProduct(vector<int> arr ) {
    int n = int(arr.size());
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min (min_ending_here * arr[i], 1);
        }
        else if (arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
        }
        else {
            int temp = max_ending_here;
            max_ending_here = max (min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }
        if (max_so_far <  max_ending_here) {
            max_so_far  =  max_ending_here;
        }
    }
    
    return max_so_far;
}


int main() {
    cout << "\nEnter Size\t:\t";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nMaximum Product\t:\t" << maxSubarrayProduct(arr) << "\n";
}
