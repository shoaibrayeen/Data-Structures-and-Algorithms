//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>

using namespace std;

#define N 8

//celebrity = 2
bool MATRIX[N][N] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}};

/*
 celebrity = 1
 bool MATRIX[N][N] = {
 {0, 1, 0, 0},
 {0, 0, 0, 0},
 {0, 1, 0, 0},
 {0, 1, 0, 0}};
 
 
 
 No Celebrity
 bool MATRIX[N][N] = {
 {0, 1, 0, 0},
 {0, 0, 1, 0},
 {0, 1, 0, 0},
 {0, 1, 0, 0}};
 */

bool knows(int a, int b) {
    return MATRIX[a][b];
}

int findCelebrity(int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        if (knows(start, end)) {
            start++;
        }
        else {
            end--;
        }
    }
    for (int i = 0; i < n; i++) {
        if ( (i != start) &&  ( knows(start, i) || !knows(i, end)) ){
            return -1;
        }
    }
    
    return start;
}

int main() {
    int n = 4;
    if ( findCelebrity(n) == -1 ) {
        cout << "\nNo celebrity\n";
    }
    else {
        cout << "\nCelebrity ID\t:\t" << findCelebrity(n) << endl;
    }
    
    return 0;
}
