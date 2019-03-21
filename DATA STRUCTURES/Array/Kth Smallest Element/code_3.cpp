//
//  code_3.cpp
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

class MaxHeap {
    int *harr;
    int heap_size;
public:
    MaxHeap(int a[], int size);
    void maxHeapify(int i);
    int parent(int i) {
        return (i-1)/2;
        
    }
    int left(int i) {
        return (2*i + 1);
        
    }
    int right(int i) {
        return (2*i + 2);
        
    }
    
    int extractMax();
    int getMax() {
        return harr[0];
        
    }
    void replaceMax(int x) {
        harr[0] = x;
        maxHeapify(0);
    }
};

MaxHeap::MaxHeap(int a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0) {
        maxHeapify(i);
        i--;
    }
}

int MaxHeap::extractMax() {
    if (heap_size == 0) {
        return INT_MAX;
    }
    int root = harr[0];
    if (heap_size > 1) {
        harr[0] = harr[heap_size-1];
        maxHeapify(0);
    }
    heap_size--;
    
    return root;
}

void MaxHeap::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i]) {
        largest = l;
    }
    if (r < heap_size && harr[r] > harr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&harr[i], &harr[largest]);
        maxHeapify(largest);
    }
}

int kthSmallest(int arr[], int n, int k) {
    MaxHeap obj(arr, k);
    for (int i = k; i < n; i++) {
        if (arr[i] < obj.getMax()) {
            obj.replaceMax(arr[i]);
        }
    }
    return obj.getMax();
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
