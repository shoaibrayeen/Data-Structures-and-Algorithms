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

struct Query {
    int L, R;
};

void getRangeMean(vector<int>arr, vector<Query> List) {
    int n = int(arr.size());
    int listSize = int(List.size());
    vector<int> prefixSum(n);
    
    prefixSum[0] = arr[0];
    
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    double mean;
    int L , R;
    for ( int i = 0; i < listSize; i++ ) {
        L = List[i].L;
        R = List[i].R;
        if (L == 0) {
            mean = double(prefixSum[R])/double(R+1);
        }
        else {
            mean = double(prefixSum[R] - prefixSum[L - 1]) / double(R - L + 1);
        }
        cout << "\nMean for ( " << L << " , " << R << " )\t:\t" << mean << "\n";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "\nEnter Size of Array\t:\t";
    cin >> size;
    vector<int> array(size);
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < size; i++ ) {
        cin >> array[i];
    }
    cout << "\nEnter Number of Queries\t:\t";
    cin >> size;
    vector<Query> List(size);
    cout << "\nEnter Queries (L,R) Form\n";
    for ( int i = 0; i < size; i++ ) {
        cin >> List[i].L;
        cin >> List[i].R;
    }
    getRangeMean(array,List);
    return 0;
}
