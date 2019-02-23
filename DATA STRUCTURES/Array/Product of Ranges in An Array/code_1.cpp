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

struct Range {
    int L, R, P;
};


void getRangeProduct(vector<int> array , vector<Range> List) {
    int querySize = int(List.size());
    int L , R , res;
    for ( int i = 0; i < querySize; i++ ) {
        L = List[i].L - 1;
        R = List[i].R - 1;
        res = 1;
        for (int j = L; j <= R; j++) {
            res = res* array[j];
            res = res % List[i].P;
        }
        cout << "\nProduc for ( " << L + 1 << " , " << R + 1 << " )\t:\t" << res << "\n";
    }
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
    cout << "\nEnter Number of Queries\t:\t";
    cin >> n;
    vector<Range> List(n);
    cout << "\nEnter Range (L,R,Prime) Form\n";
    for (int i = 0; i < n; i++ ) {
        cin >> List[i].L;
        cin >> List[i].R;
        cin >> List[i].P;
    }
    getRangeProduct(array , List);
    return 0;
}

