//
//  q3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 30/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int total;

void nQueens(int *arr , int n, int k);  // function that uses N queue
bool issafe(int * arr , int k, int i); // to check queen can be placed or not.
void display(int*arr , int n);        // displaying different number of solutions


void nQueens(int *arr , int n, int k) {
    for (int i = 1; i <= n; i++ ){
        if ( issafe(arr , k , i) ) {
            arr[k] = i;
            if (k == n) {
                display(arr , n);
            }
            else {
                nQueens(arr , n , k + 1 );
            }
        }
    }
}

bool issafe(int* arr , int k, int i){
    for (int j = 1; j <= k - 1; j++ ) {
        if ( arr[j] == i || ( abs(arr[j] - i) == abs(j - k) ) )
            return false;
    }
    return true;
}

void display(int* arr , int n) {
    ++total;
    cout << "\n--------------------------\n";
    cout << "Possible Place for Queen " << total << endl;
    cout << "--------------------------\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (arr[i] != j) {
                cout << "\t-";
            }
            else {
                cout << "\tQ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "\nEnter Value of N\t:\t";
    cin >> n;
    int *arr = new int[n];
    nQueens(arr , n , 1);
    cout << "\nNumber of Solutions\t:\t" << total << endl;
    delete []arr;
    return 0;
}
/*
 Enter Value of N    :    5
 
 --------------------------
 Possible Place for Queen 1
 --------------------------
 Q    -    -    -    -
 -    -    Q    -    -
 -    -    -    -    Q
 -    Q    -    -    -
 -    -    -    Q    -
 
 --------------------------
 Possible Place for Queen 2
 --------------------------
 Q    -    -    -    -
 -    -    -    Q    -
 -    Q    -    -    -
 -    -    -    -    Q
 -    -    Q    -    -
 
 --------------------------
 Possible Place for Queen 3
 --------------------------
 -    Q    -    -    -
 -    -    -    Q    -
 Q    -    -    -    -
 -    -    Q    -    -
 -    -    -    -    Q
 
 --------------------------
 Possible Place for Queen 4
 --------------------------
 -    Q    -    -    -
 -    -    -    -    Q
 -    -    Q    -    -
 Q    -    -    -    -
 -    -    -    Q    -
 
 --------------------------
 Possible Place for Queen 5
 --------------------------
 -    -    Q    -    -
 Q    -    -    -    -
 -    -    -    Q    -
 -    Q    -    -    -
 -    -    -    -    Q
 
 --------------------------
 Possible Place for Queen 6
 --------------------------
 -    -    Q    -    -
 -    -    -    -    Q
 -    Q    -    -    -
 -    -    -    Q    -
 Q    -    -    -    -
 
 --------------------------
 Possible Place for Queen 7
 --------------------------
 -    -    -    Q    -
 Q    -    -    -    -
 -    -    Q    -    -
 -    -    -    -    Q
 -    Q    -    -    -
 
 --------------------------
 Possible Place for Queen 8
 --------------------------
 -    -    -    Q    -
 -    Q    -    -    -
 -    -    -    -    Q
 -    -    Q    -    -
 Q    -    -    -    -
 
 --------------------------
 Possible Place for Queen 9
 --------------------------
 -    -    -    -    Q
 -    Q    -    -    -
 -    -    -    Q    -
 Q    -    -    -    -
 -    -    Q    -    -
 
 --------------------------
 Possible Place for Queen 10
 --------------------------
 -    -    -    -    Q
 -    -    Q    -    -
 Q    -    -    -    -
 -    -    -    Q    -
 -    Q    -    -    -
 
 Number of Solutions    :    10
*/
