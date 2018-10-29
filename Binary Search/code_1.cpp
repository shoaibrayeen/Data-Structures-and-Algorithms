//
//  main.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 28/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int binarySearch(int* arr, int low, int high, int key) { 
   if (r >= l) { 
        int mid = low + (high - low)/2;
        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] > key) {
            return binarySearch(arr, low, mid-1, key); 
        }
        return binarySearch(arr, mid+1, high, key; 
   } 
   return -1; 
} 
  
int main() { 
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int arr[n];
    cout << "\nEnter Elements\n";
    for(int i =0; i < n; i++ ) {
      cin >> arr[i];
    }
    int key;
    cout << "\nEnter key to be search\t:\t";
    cin >> key;
    int temp = binarySearch(arr,0,n-1,key);
    if( temp == -1 ) {
      cout << "\nKey not Found\n";
    }
    else {
      cout << "\nKey Found at " << temp << " Position\n";
    }
    return 0; 
}
