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

struct Query {
    int L, R;
};

void getRangeMean(vector<int>arr, vector<Query> List) {
    int listSize = int(List.size());
    for ( int j = 0; j < listSize; j++ ) {
        int sum = 0, count = 0;
        int L = List[j].L , R = List[j].R;
        for (int i = L; i <= R; i++) {
            sum += arr[i];
            count++;
        }
        double mean = double(sum) / double(count);
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
