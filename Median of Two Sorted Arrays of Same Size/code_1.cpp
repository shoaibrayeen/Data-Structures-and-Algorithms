//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int getMedian(int ar1[], int ar2[], int n){
    int i = 0;
    int j = 0;
    int m1 = -1, m2 = -1;
    for (int count = 0; count <= n; count++) {
        if (i == n) {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
        else if (j == n) {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
        
        if (ar1[i] < ar2[j]) {
            m1 = m2;
            m2 = ar1[i];
            i++;
        }
        else {
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }
    
    return (m1 + m2)/2;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int a1[n] , a2[n];
    cout << "\nEnter 1st Array Elements\n";
    for ( int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    cout << "\nEnter 2nd Array Elements\n";
    for ( int i = 0; i < n; i++) {
        cin >> a2[i];
    }
    cout << "\nMedian\t:\t" << getMedian(a1, a2, n) ;
    cout << "\n";
    return 0;
}
