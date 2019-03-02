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

int getMaxSum(vector<int> array) {
    int n = int(array.size());
    int include = array[0];
    int exclude = 0;
    int temp;
    
    for (int i = 1; i < n; i++) {
        temp = (include > exclude)? include: exclude;
        include = exclude + array[i];
        exclude = temp;
    }
    return ((include > exclude)? include : exclude);
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
    cout << "\nMaximum Sum\t:\t" << getMaxSum(array) << "\n";
    return 0;
}

