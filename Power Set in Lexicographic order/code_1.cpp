//
//  q5.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 05/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <bits/stdc++.h> 
using namespace std; 
void permuteRec(string str, int n , int index = -1, string curr = "") { 
    if (index == n) {
        return; 
    }
    cout << curr << "\n"; 
    for (int i = index + 1; i < n; i++) { 
        curr += str[i]; 
        permuteRec(str, n, i, curr); 
        curr = curr.erase(curr.size() - 1);  
    } 
    return; 
} 

void powerSet(string str) { 
    sort(str.begin(), str.end()); 
    permuteRec(str, str.size()); 
} 
  
int main() { 
    string str;
    cout << "\nEnter String\t:\t";
    cin >> str;
    powerSet(str); 
    return 0; 
} 
