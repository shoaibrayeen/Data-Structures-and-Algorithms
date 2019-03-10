//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int repeated_digit(int n) {
    unordered_set<int> s;
    while(n != 0) {
        int d = n % 10;
        if(s.find(d) != s.end()) {
            return 0;
        }
        s.insert(d);
        n = n / 10;
    }
    return 1;
}

int getUnrepeatedDigitsNumber(int L,int R) {
    int answer = 0;
    for(int i = L; i <= R; ++i) {
        answer = answer + repeated_digit(i);
    }
    
    return answer ;
}

int main() {
    int L , R;
    cout << "\nEnter L\t:\t";
    cin >> L;
    cout << "\nEnter R\t:\t";
    cin >> R;
    cout << "\nUnrepeated Digits-Numbers Count\t:\t" << getUnrepeatedDigitsNumber(L , R) << "\n";
    return 0;
}


