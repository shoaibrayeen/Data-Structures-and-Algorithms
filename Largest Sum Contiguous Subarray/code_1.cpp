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
  
int maxSubArraySum(int a[], int size) { 
    int max_so_far = INT_MIN, max_ending_here = 0; 
    for (int i = 0; i < size; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
  
int main()  {
  int n;
  cout << "\nEnter Size of Set\t:\t";
  cin >> n;
  int a[n];
  cout << "\nEnter Set Elements\n";
  for(int i = 0; i < n ; i++ ) {
    cin >> a[i];
  }
  cout << "\nMaximum contiguous sum is " << maxSubArraySum(a, n); 
  return 0; 
}
