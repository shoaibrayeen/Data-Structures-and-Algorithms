
//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Interval {
    int start, end;
};

bool compareInterval(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

void mergeIntervals(vector<Interval>arr) {
    int n = int(arr.size());
    if (n <= 0) {
        return;
    }
    stack<Interval> s;
    sort(arr.begin(), arr.end(), compareInterval);
    s.push(arr[0]);
    for (int i = 1 ; i < n; i++) {
        Interval top = s.top();
        if (top.end < arr[i].start) {
            s.push(arr[i]);
        }
        else if (top.end < arr[i].end) {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    cout << "\nMerged Intervals\t:\t";
    while (!s.empty()) {
        Interval temp = s.top();
        cout << "( " << temp.start << " , " << temp.end << " )";
        s.pop();
    }
    cout << endl;
    return;
}

int main() {
    int n;
    cout << "\nEnter Number of Intervals\t:\t";
    cin >> n;
    vector<Interval> array(n);
    cout << "\nEnter Range (L,R) Form\n";
    for (int i = 0; i < n; i++ ) {
        cin >> array[i].start;
        cin >> array[i].end;
    }
    mergeIntervals(array);
    return 0;
}
