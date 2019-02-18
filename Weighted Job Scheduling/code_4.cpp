//
//  code_4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Job {
    int start, finish, profit;
};

int findSum(vector<Job> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum +=  arr[i].profit;
    }
    return sum;
}
int compare(Job x, Job y) {
    return x.start < y.start;
}

void findMaxProfit(vector<Job> arr) {
    sort(arr.begin(), arr.end(), compare);
    vector<vector<Job>> L(arr.size());
    L[0].push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if ((arr[j].finish <= arr[i].start) && (findSum(L[j]) > findSum(L[i])))
                L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }
    
    vector<Job> maxChain;
    for (int i = 0; i < L.size(); i++) {
        if (findSum(L[i]) > findSum(maxChain)) {
            maxChain = L[i];
        }
    }
    cout << "\nSelected Jobs\t:\t";
    for (int i = 0; i < maxChain.size(); i++) {
        cout << "(" <<  maxChain[i].start << ", " << maxChain[i].finish << ", " <<  maxChain[i].profit << ") ";
    }
    cout << endl;
}

int main() {
    cout << "\nEnter Number of Jobs\t:\t";
    int n;
    cin >> n;
    vector<Job> arr(n);
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
    findMaxProfit(arr);
    return 0;
}
