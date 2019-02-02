//
//  code_1.cpp
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

int latestNonConflict(Job arr[], int i) {
    for (int j=i-1; j>=0; j--) {
        if (arr[j].finish <= arr[i-1].start) {
            return j;
        }
    }
    return -1;
}

int findMaxProfitRec(Job arr[], int n) {
    if (n == 1) {
        return arr[n-1].profit;
    }
    int inclProf = arr[n-1].profit;
    int i = latestNonConflict(arr, n);
    if (i != -1) {
        inclProf += findMaxProfitRec(arr, i+1);
    }
    int exclProf = findMaxProfitRec(arr, n-1);
    
    return max(inclProf,  exclProf);
}

int findMaxProfit(Job arr[], int n) {
    sort(arr, arr+n, jobComparataor);
    return findMaxProfitRec(arr, n);
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
