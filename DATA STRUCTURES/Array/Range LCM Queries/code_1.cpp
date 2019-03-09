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

int getGCD(int num1 , int num2 ) {
    if (num1 == 0) {
        return num2;
    }
    if (num2 == 0) {
        return num1;
    }
    if (num1 == num2) {
        return num2;
    }
    if (num1 > num2) {
        return getGCD(num1 - num2, num2);
    }
    return getGCD(num1, num2-num1);
}

void getLCMInRanges(vector<int> array , vector<Interval> list) {
    int numberOfRange = int(list.size());
    int lcm , temp , temp2;
    for ( int i = 0; i < numberOfRange; i++) {
        temp = getGCD( array[list[i].start] , array[list[i].start + 1]);
        lcm = (array[list[i].start] * array[list[i].start + 1])/temp;
        if ( list[i].end  - list[i].start > 1) {
            for ( int j = list[i].start + 2; j <= list[i].end; j++ ) {
                temp = getGCD(lcm, array[j]);
                temp2 = (lcm * array[j])/temp;
                lcm = temp2;
            }
        }
        cout << "\nFor Range ( " << list[i].start << " , " << list[i].end << ")\t|\tLCM\t:\t" << lcm << endl;
    }
    cout << endl;
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
    getLCMInRanges(arr, array);
    return 0;
}


