//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int median(int [], int);  
 
int getMedian(int ar1[],int ar2[], int n) { 
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return (ar1[0] +  ar2[0]) / 2; 
    }
    if (n == 2) {
        return (max(ar1[0], ar2[0]) +  min(ar1[1], ar2[1])) / 2; 
    }
    int m1 = median(ar1, n);
    int m2 = median(ar2, n);  
    if (m1 == m2) {
        return m1; 
    }
    if (m1 < m2) { 
        if (n % 2 == 0) {
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1); 
        }
        return getMedian(ar1 + n / 2, ar2, n - n / 2); 
    } 
    if (n % 2 == 0) {
        return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1); 
    }
    return getMedian(ar2 + n / 2, ar1, n - n / 2); 
} 
  
int median(int arr[], int n) { 
    if (n % 2 == 0) {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2; 
    }
    else {
        return arr[n / 2];
    }
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
