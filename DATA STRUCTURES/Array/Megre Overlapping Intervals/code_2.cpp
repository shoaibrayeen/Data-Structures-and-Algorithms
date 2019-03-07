//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start, end;
};

bool compareInterval(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

void mergeIntervals(vector<Interval>arr) {
    int n = int(arr.size());
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (index != 0 && arr[index-1].start <= arr[i].end) {
            while (index != 0 && arr[index-1].start <= arr[i].end) {
                arr[index-1].end = max(arr[index-1].end, arr[i].end);
                arr[index-1].start = min(arr[index-1].start, arr[i].start);
                index--;
            }
        }
        else {
            arr[index] = arr[i];
        }
        index++;
    }
    cout << "\nMerged Intervals\t:\t";
    for (int i = 0; i < index; i++) {
        cout << "[" << arr[i].start << ", " << arr[i].end << "] ";
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
