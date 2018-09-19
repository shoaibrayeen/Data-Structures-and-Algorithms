//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

int cutRod(int price[], int n) { 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
   for (i = 1; i<=n; i++) { 
       int max_val = -1; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 

int main () {
    int number_rod;
    cout << "\nNumber of Rods\t:\t";
    cin >> number_rod;
    int array[number_rod];
    cout << "\nEnter Price\n";
    for( int i = 0; i < number_rod; ++i ) {
        cin >> array[i];
    }
    cout <<"\nThe result is\t:\t" << cutRod(array , number_rod);
    cout << endl;
    return 0;
}
