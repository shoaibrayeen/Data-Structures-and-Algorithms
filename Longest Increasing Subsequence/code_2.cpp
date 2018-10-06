/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
using namespace std;

int lis_fun( int *arr, int n ) {  
    int lis[n]; 
   
    lis[0] = 1;    
    for (int i = 1; i < n; i++ ){ 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ ) {   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  {
                lis[i] = lis[j] + 1;  
            }
        }
    } 
    return *max_element(lis, lis+n); 
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
    cout << "\Length of LIS\t:\t" << lis_fun(arr,n); 
    return 0; 
}
