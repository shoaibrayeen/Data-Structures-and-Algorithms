//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

struct Query {
    int L, R , X;
};

int block;

bool compare(Query x, Query y) {
    if (x.L/block != y.L/block) {
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}


void getQueryResults(vector<int> a,vector<Query> q) {
    int n = int(a.size());
    int m = int(q.size());
    block = (int)sqrt(n);
    sort(q.begin(), q.end(), compare);
    int currL = 0, currR = 0;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int L = q[i].L, R = q[i].R, X = q[i].X;
        while (currL < L) {
            mp[a[currL]]--;
            currL++;
        }
        while (currL > L) {
            mp[a[currL - 1]]++;
            currL--;
        }
        while (currR <= R) {
            mp[a[currR]]++;
            currR++;
        }
        while (currR > R + 1) {
            mp[a[currR - 1]]--;
            currR--;
        }
        if (mp[X] != 0) {
            cout << X << " exists between [" << L << ", " << R << "] " << endl;
        }
        else {
            cout << X << " does not exist between [" << L << ", " << R << "] " << endl;
        }
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
    cout << "\nEnter Queries (L,R,Element) Form\n";
    for ( int i = 0; i < size; i++ ) {
        cin >> List[i].L;
        cin >> List[i].R;
        cin >> List[i].X;
    }
    getQueryResults(array,List);
    return 0;
}
