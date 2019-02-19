//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Query {
    int L, R;
};

int block;

bool compare(Query x, Query y) {
    if (x.L/block != y.L/block) {
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}


void getQuerySums( vector<int> array , vector<Query> List ) {
    int n = int(array.size());
    int m = int(List.size());
    block = (int)sqrt(n);
    sort(List.begin(), List.end(), compare);
    int currL = 0, currR = 0;
    int currSum = 0;
    for (int i = 0; i < m; i++) {
        int L = List[i].L, R = List[i].R;
        while (currL < L) {
            currSum -= array[currL];
            currL++;
        }
        while (currL > L) {
            currSum += array[currL-1];
            currL--;
        }
        while (currR <= R) {
            currSum += array[currR];
            currR++;
        }
        while (currR > R+1) {
            currSum -= array[currR-1];
            currR--;
        }
        cout << "Sum of [" << L << ", " << R << "]\t:\t"  << currSum << endl;
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
