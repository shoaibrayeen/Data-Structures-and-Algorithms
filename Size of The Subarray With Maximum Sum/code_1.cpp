//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream> 
#include<climits> 
using namespace std; 
  
int maxSubArraySum(int a[], int size)  { 
    int max_so_far = INT_MIN, max_ending_here = 0, start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) { 
        max_ending_here += a[i]; 
        if (max_so_far < max_ending_here) { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
        if (max_ending_here < 0) { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
      
    return (end - start + 1); 
} 
  
int main() { 
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Elements of Array\n";
    for(int i =0; i < n; i++ ) {
      cin >> arr[i];
    }
    cout << "\Length of SubArray\t:\t" << maxSubArraySum(arr,n); 
    return 0; 
}
