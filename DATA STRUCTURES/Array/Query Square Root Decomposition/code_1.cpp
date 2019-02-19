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

void getQuerySums( vector<int> array , vector<Query> List ) {
    int m = int(List.size());
    for (int i = 0; i < m; i++) {
        int L = List[i].L, R = List[i].R;
        int sum = 0;
        for (int j = L; j <= R; j++) {
            sum += array[j];
        }
        cout << "\nSum of [" << L << ", " << R << "]\t:\t"  << sum << endl;
    }
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
    getQuerySums(array,List);
    return 0;
}
