//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
  
int smallestSumSubarr(int arr[], int n) { 
    int min_ending_here = INT_MAX; 
    int min_so_far = INT_MAX; 
    for (int i = 0; i < n; i++) { 
        if (min_ending_here > 0) {
            min_ending_here = arr[i]; 
        }     
        else {
            min_ending_here += arr[i]; 
        } 
        min_so_far = min(min_so_far, min_ending_here);             
    }
    return min_so_far; 
} 
  
  
int main() { 
  int n;
  cout << "\nEnter Size of Set\t:\t";
  cin >> n;
  int a[n];
  cout << "\nEnter Set Elements\n";
  for(int i = 0; i < n ; i++ ) {
    cin >> a[i];
  } 
    cout << "\nSmallest sum\t:\t" << smallestSumSubarr(a, n); 
    return 0;      
}  
