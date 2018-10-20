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

int compare(Pair x, Pair y)  { 
    return x.a < y.a; 
} 

void maxChainLength(vector<Pair> arr) { 
    sort(arr.begin(), arr.end(), compare); 
    vector<vector<Pair> > L(arr.size()); 
    L[0].push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) { 
        for (int j = 0; j < i; j++) { 
            if ((arr[j].b < arr[i].a) &&  (L[j].size() > L[i].size())) {
                L[i] = L[j]; 
            }
        } 
        L[i].push_back(arr[i]); 
    } 
    vector<Pair> maxChain; 
    for (vector<Pair> x : L) {
        if (x.size() > maxChain.size()) {
            maxChain = x; 
        }
    }
    for (Pair pair : maxChain) {
        cout << "(" << pair.a << " , " << pair.b << ") "; 
    }
} 

int main() { 
    struct pair arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} }; 
    int n = sizeof(arr)/sizeof(arr[0]);  
    maxChainLength( arr, n); 
    return 0; 
} 
