/
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

/*
    Time Complexity: O(n^2)
    Auxiliary Space : O(n)
*/
#include <iostream>
using namespace std;

long long int lis(long long int* arr, int n) { 
    long long int mpis[n]; 
    for (int i = 0; i < n; i++) {
        mpis[i] = arr[i]; 
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                mpis[i] = mpis[j] * arr[i]; 
            }
         }
    }
    return *max_element(mpis, mpis + n); 
}   
  
int main() { 
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    long long int arr[n];
    cout << "\nEnter Sequence\n";
    for(int i =0; i < n; i++ ) {
      cin >> arr[i];
    }
    cout << "\Maximum product\t:\t" << lis(arr,n); 
    return 0; 
}
