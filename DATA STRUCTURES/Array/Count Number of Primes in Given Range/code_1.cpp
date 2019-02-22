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
const int MAX = 10000;

struct Range {
    int L, R;
};

int prefix[MAX + 1];

void buildPrefix() {
    bool prime[MAX + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAX; p++) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= MAX; i += p) {
                prime[i] = false;
            }
        }
    }
    prefix[0] = prefix[1] = 0;
    for (int p = 2; p <= MAX; p++) {
        prefix[p] = prefix[p - 1];
        if (prime[p]) {
            prefix[p]++;
        }
    }
}
void query(vector<Range> List) {
    buildPrefix();
    int n = int(List.size());
    int L , R;
    for ( int i = 0; i < n; i++ ) {
        L = List[i].L;
        R = List[i].R;
        cout << "\nCount for ( " << L << " , " << R << " )\t:\t" << prefix[R] - prefix[L - 1] << "\n";
    }
}

int main() {
    int n;
    cout << "\nEnter Number of Queries\t:\t";
    cin >> n;
    vector<Range> List(n);
    cout << "\nEnter Range (L,R) Form\n";
    for (int i = 0; i < n; i++ ) {
        cin >> List[i].L;
        cin >> List[i].R;
    }
    query(List);
    return 0;
}
