//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

struct Job {
    int start, finish, profit;
};

bool jobComparataor(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

int binarySearch(Job jobs[], int index) {
    int lo = 0, hi = index - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start) {
            if (jobs[mid + 1].finish <= jobs[index].start) {
                lo = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            hi = mid - 1;
        }
    }
    
    return -1;
}

int findMaxProfit(Job arr[], int n) {
    sort(arr, arr+n, jobComparataor);
    int *table = new int[n];
    table[0] = arr[0].profit;
    for (int i=1; i<n; i++) {
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1) {
            inclProf += table[l];
        }
        table[i] = max(inclProf, table[i-1]);
    }
    int result = table[n-1];
    delete[] table;
    return result;
}

int main() {
    cout << "\nEnter Number of Jobs\t:\t";
    int n;
    cin >> n;
    Job arr[n];
    cout << "\nEnter (Start Time , Finish Time , Profit) Order\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i].start;
        cin >> arr[i].finish;
        cin >> arr[i].profit;
    }
    /*
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
     */
    cout << "\nOptimal profit\t:\t" << findMaxProfit(arr, n) << endl;
    return 0;
}
