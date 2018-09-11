//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<iostream>
using namespace std;
bool isSubsetSum(int* set, int n, int sum)  {  
   if (sum == 0) 
     return true; 
   if (n == 0 && sum != 0) 
     return false;  
   if (set[n-1] > sum) 
     return isSubsetSum(set, n-1, sum); 
   return isSubsetSum(set, n-1, sum) ||  isSubsetSum(set, n-1, sum-set[n-1]); 
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
