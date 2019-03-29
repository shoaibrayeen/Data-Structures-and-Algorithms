//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

#define N 8

bool MATRIX[N][N] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}};

bool knows(int a, int b) {
    return MATRIX[a][b];
}

int findCelebrity(int n) {
    stack<int> st;
    
    int C;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    int A = st.top();
    st.pop();
    int B = st.top();
    st.pop();
    
    // Find a potential celevrity
    while (st.size() > 1) {
        if (knows(A, B)) {
            A = st.top();
            st.pop();
        }
        else {
            B = st.top();
            st.pop();
        }
    }
    C = st.top();
    st.pop();
    if (knows(C, B)) {
        C = B;
    }
    
    if (knows(C, A)) {
        C = A;
    }
    for (int i = 0; i < n; i++) {
        if ( (i != C) && (knows(C, i) || !knows(i, C)) ) {
            return -1;
        }
    }
    
    return C;
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
