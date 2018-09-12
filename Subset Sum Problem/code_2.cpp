//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)  { 
    bool subset[n+1][sum+1]; 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
     for (int i = 1; i <= n; i++)  { 
       for (int j = 1; j <= sum; j++)  { 
         if(j<set[i-1]) 
            subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
            subset[i][j] = subset[i-1][j] ||  subset[i - 1][j-set[i-1]]; 
       } 
     } 
     return subset[n][sum]; 
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
