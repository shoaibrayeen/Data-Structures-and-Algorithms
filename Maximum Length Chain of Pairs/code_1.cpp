//
//  q2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 18/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream> 
#include<stdlib.h> 
using namespace std;
  
struct pair { 
  int a; 
  int b; 
}; 

int maxChainLength( struct pair arr[], int n) { 
   int max = 0; 
   int m[n];
   for (int i = 0; i < n; i++ ) {
      m[i] = 1; 
   }
   for (int  i = 1; i < n; i++ ) {
      for (int j = 0; j < i; j++ ) {
         if ( arr[i].a > arr[j].b && m[i] < m[j] + 1) {
            m[i] = m[j] + 1; 
         }
      }
   }
   for (int i = 0; i < n; i++ ) {
      if ( max < m[i] ) { 
         max = m[i]; 
      }
   }
   delete[] m;
   return max; 
} 

int main() { 
    struct pair arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} }; 
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout << "\nMaximum Chain length\t:\t" << maxChainLength( arr, n); 
    return 0; 
} 
