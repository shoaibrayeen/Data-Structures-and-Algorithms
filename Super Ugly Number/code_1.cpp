//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include<vector>
#include <set>
using namespace std;

int superUgly(int n, int primes[], int k) {
    vector<int> nextMultiple(primes, primes+k);
    int multiple_Of[k];
    memset(multiple_Of, 0, sizeof(multiple_Of));
    set<int> ugly;
    ugly.insert(1);
    while (ugly.size() != n) {
        int next_ugly_no = *min_element(nextMultiple.begin(),nextMultiple.end());
        ugly.insert(next_ugly_no);
        for (int j=0; j<k; j++) {
            if (next_ugly_no == nextMultiple[j]) {
                multiple_Of[j]++;
                set<int>::iterator it = ugly.begin();
                for (int i=1; i<=multiple_Of[j]; i++) {
                    it++;
                }
                nextMultiple[j] = primes[j] * (*it);
                break;
            }
        }
    }
    set<int>::iterator it = ugly.end();
    it--;
    return *it;
}

int main() {
    int total;
    cout << "\nSize of Prime List\t:\t";
    cin >> total;
    int *prime = new int[total];
    cout << "\nEnter Prime List\n";
    for( int i = 0; i < total; i++ ) {
        cin >> prime[i];
    }
    cout << "\nEnter N\t:\t";
    int N;
    cin >> N;
    cout << "\nNth Super Ugly Number\t:\t" << superUgly(N, prime, total) << endl;;
    return 0;
}
