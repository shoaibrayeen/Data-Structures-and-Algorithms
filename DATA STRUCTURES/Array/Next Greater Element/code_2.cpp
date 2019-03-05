//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printNextGreaterElement(vector<int> arr) {
    int n = int(arr.size());
    cout << "\nElement\t|\tNGE\n";
    cout << "------------------\n";
    stack < int > s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && s.top() < arr[i]) {
            cout << "\t" << s.top() << "\t|\t" << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (s.empty() == false) {
        cout << "\t" << s.top() << "\t|\t" << -1 << endl;
        s.pop();
    }
}
int main() {
    int n;
    cout << "\nEnter Size of Array\t:\t";
    cin >> n;
    vector<int> array(n);
    cout << "\nEnter Array Element\n";
    for (int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    printNextGreaterElement(array);
    return 0;
}

