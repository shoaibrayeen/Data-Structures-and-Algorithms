//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int lis_res( int *arr, int n, int *max_ref) { 
    if (n == 1) {
        return 1;
    }
    int res, max_ending_here = 1; 
    for (int i = 1; i < n; i++) { 
        res = lis_res(arr, i, max_ref); 
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here) {
            max_ending_here = res + 1; 
        }
    } 
    if (*max_ref < max_ending_here) {
       *max_ref = max_ending_here;  
    }
    return max_ending_here; 
} 

int lis(int arr[], int n) {
    int max = 1; 
    lis_res( arr, n, &max );
    return max; 
} 
  
int main() { 
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Sequence\n";
    for(int i =0; i < n; i++ ) {
      cin >> arr[i];
    }
    cout << "\Length of LIS\t:\t" << lis(arr,n); 
    return 0; 
}
