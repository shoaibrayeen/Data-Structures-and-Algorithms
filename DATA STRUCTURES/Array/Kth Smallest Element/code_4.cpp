//
//  code_4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
    int *harr;
    int heap_size;
public:
    MinHeap(int a[], int size);
    void MinHeapify(int i);
    int parent(int i) {
        return (i-1)/2;
        
    }
    int left(int i) {
        return (2*i + 1);
        
    }
    int right(int i) {
        return (2*i + 2);
        
    }
    
    int extractMin();
    int getMin() {
        return harr[0];
        
    }
};

MinHeap::MinHeap(int a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin() {
    if (heap_size == 0) {
        return INT_MAX;
    }
    int root = harr[0];
    if (heap_size > 1) {
        harr[0] = harr[heap_size-1];
        MinHeapify(0);
    }
    heap_size--;
    
    return root;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) {
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int kthSmallest(int arr[], int n, int k) {
    MinHeap obj(arr, n);
    for (int i=0; i<k-1; i++) {
        obj.extractMin();
    }
    return obj.getMin();
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
    cout << "\nKth Smallest Element\t:\t" << kthSmallest( a ,  n , k ) << endl;
    delete[] a;
    return 0;
}
