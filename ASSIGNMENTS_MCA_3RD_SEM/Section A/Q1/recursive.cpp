//
//  q1_recursive.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 24/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream>
#include<climits>
using namespace std;

int MatrixChainOrder(int* dim, int start, int end) {
    if(start == end) {
        return 0;
    }
    int min = INT_MAX;
    int count;
    for (int k = start; k < end; k++) {
        count = MatrixChainOrder(dim, start, k) + MatrixChainOrder(dim, k+1, end) + dim[start-1]*dim[k]*dim[end];
        
        if (count < min) {
            min = count;
        }
    }
    return min;
}
int main()  {
    int n;
    cout << "\nEnter Number of Matrix\t:\t";
    cin >> n;
    int dim[n+1];
    cout << "\nEnter Dimenstions of Matrices\n";
    for(int i = 0; i <= n ; i++ ) {
        cin >> dim[i];
    }
    cout << "\nMinimum number of multiplications\t:\t" << MatrixChainOrder(dim, 1, n) << endl;;
    return 0;
}
