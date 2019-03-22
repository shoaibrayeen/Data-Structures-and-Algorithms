//
//  code_5.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<climits>
using namespace std;

int partition(int arr[], int l, int r, int k);

int findMedian(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n/2];
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int n = r-l+1;
        int i ,median[(n+4)/5];
        for (i = 0; i < n/5; i++) {
            median[i] = findMedian(arr + l + i*5, 5);
        }
        if (i*5 < n) {
            median[i] = findMedian(arr + l + i*5, n%5);
            i++;
        }
        int medOfMed = (i == 1)? median[i-1]:
        kthSmallest(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1) {
            return arr[pos];
        }
        if (pos-l > k-1) {
            return kthSmallest(arr, l, pos-1, k);
        }
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int x) {
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x) {
            break;
        }
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main() {
    int n;
    cout << "\nEnter Size\t:\t";
    cin >> n;
    int *a = new int[n];
    cout << "\nEnter Array Elements\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    int k;
    cout << "Enter K\t:\t";
    cin >> k;
    cout << "\nKth Smallest Element\t:\t" << kthSmallest( a , 0 , n-1 , k ) << endl;
    delete[] a;
    return 0;
}
