//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)  { 
    bool subset[2][sum + 1]; 
  
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= sum; j++) { 
            if (j == 0) 
                subset[i % 2][j] = true;  
            else if (i == 0) 
                subset[i % 2][j] = false;  
            else if (arr[i - 1] <= j) 
                subset[i % 2][j] = subset[(i + 1) % 2] 
             [j - arr[i - 1]] || subset[(i + 1) % 2][j]; 
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j]; 
        } 
    } 
  
    return subset[n % 2][sum]; 
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
  int sum;
  cout << "\nEnter sum value\t:\t";
  cin >> sum;
  if (isSubsetSum(set, n, sum) == true) 
     cout << "\nTrue\n"; 
  else
      cout << "\nFalse\n";
  return 0; 
}
