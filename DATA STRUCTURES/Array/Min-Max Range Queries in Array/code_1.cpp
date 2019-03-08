//
//  code_1.cpp
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



void getMinMaxInRanges(vector<int> array , vector<Interval> list) {
    int numberOfRange = int(list.size());
    int min , max;
    for ( int i = 0; i < numberOfRange; i++) {
        min = array[list[i].start];
        max = min;
        for ( int j = list[i].start + 1; j <= list[i].end; j++ ) {
            if ( array[j] < min ) {
                min = array[j];
            }
            if ( array[j] > max ) {
                max = array[j];
                
            }
        }
        cout << "\nFor Range ( " << list[i].start << " , " << list[i].end << ")\nMinimum\t:\t" << min;
        cout << "\nMaximum\t:\t" << max << endl;
    }
}

int main() {
    int n;
    cout << "\nEnter Size of Array\t:\t";
    cin >> n;
    vector<int> arr(n);
    cout << "\nEnter Array Elements\n";
    for (int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    cout << "\nEnter Number of Intervals\t:\t";
    cin >> n;
    vector<Interval> array(n);
    cout << "\nEnter Range (L,R) Form\n";
    for (int i = 0; i < n; i++ ) {
        cin >> array[i].start;
        cin >> array[i].end;
    }
    getMinMaxInRanges(arr, array);
    return 0;
}


