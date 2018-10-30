//
//  q3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 30/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

string commonPrefixString(string str1, string str2) { 
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
    for (int i=0, j=0; i<=n1-1 && j<=n2-1; i++,j++) { 
        if (str1[i] != str2[j]) { 
            break; 
        }
        result.push_back(str1[i]); 
    } 
    return (result); 
} 
 
string commonPrefix(string *arr, int low, int high) { 
    if (low == high) {
        return (arr[low]); 
    }
    if (high > low) { 
        int mid = low + (high - low) / 2; 
        string str1 = commonPrefix(arr, low, mid); 
        string str2 = commonPrefix(arr, mid+1, high); 
        return (commonPrefixString(str1, str2)); 
    } 
} 
 
  
int main() { 
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    string arr[n];
    cout << "\nEnter Strings\n";
    for(int i =0; i < n; i++ ) {
      cin >> arr[i];
    }
    string ans = commonPrefix(arr, 0, n-1);
    if (ans.length()) {
        cout << "The longest common prefix\t:\t" << ans; 
    }
    else {
        cout << "\nNo common prefix!\n";
    }
    return 0; 
}
