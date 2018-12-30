//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void printArray(int stream[], int n) {
    for (int i = 0; i < n; i++) {
        cout << stream[i];
    }
    cout << "\n";
}

void selectKItems(int stream[], int n, int k) {
    int reservoir[k];
    int i;
    for (i = 0; i < k; i++) {
        reservoir[i] = stream[i];
    }
    srand(time(NULL));
    for (; i < n; i++) {
        int j = rand() % (i+1);
        if (j < k) {
            reservoir[j] = stream[i];
        }
    }
    
    cout << "\nKrandomly selected item\t:\t";
    printArray(reservoir, k);
}

int main() {
    int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(stream)/sizeof(stream[0]);
    int k = 5;
    selectKItems(stream, n, k);
    return 0;
}
