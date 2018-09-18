//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 31/07/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

int cutRod(int *price, int n)  { 
   if (n <= 0) 
     return 0; 
   int max_val = -1; //price can't be negative so using negative value initially to compare.
   for (int i = 0; i < n; i++) {
         max_val = max(max_val, price[i] + cutRod(price, n-i-1)); 
   }
   return max_val; 
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
