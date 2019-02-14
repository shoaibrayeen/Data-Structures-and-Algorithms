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


using namespace std;

double getMean(vector<int> array) {
    int sum = 0;
    int n = int(array.size());
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return (double)sum/(double)n;
}


double getMedian(vector<int> array) {
    int n = int(array.size());
    sort(array.begin(), array.end() );
    if (n % 2 != 0) {
        return (double)array[n/2];
    }
    return (double)(array[(n-1)/2] + array[n/2])/2.0;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    cout << "\nEnter Array Elements\n";
    vector <int> array(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nMean\t:\t" << getMean(array);
    cout << "\nMedian\t:\t" << getMedian(array) << "\n";
    return 0;
}
