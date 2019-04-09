//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

int search(int arr[], int l, int h, int key) {
    if (l > h) {
        return -1;
    }
    int mid = (l+h)/2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[l] <= arr[mid]) {
        if (key >= arr[l] && key <= arr[mid]) {
            return search(arr, l, mid-1, key);
        }
        return search(arr, mid+1, h, key);
    }
    if (key >= arr[mid] && key <= arr[h]) {
        return search(arr, mid+1, h, key);
    }
    return search(arr, l, mid-1, key);
}

int main() {
    int n;
    cout << "\nEnter Number of Elements\t:\t";
    cin >> n;
    cout << "\nEnter Array Element\t:\t";
    int array[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> array[i];
    }
    cout << "\nEnter Key Element\t:\t";
    int key;
    cin >> key;
    int i = search(array, 0, n-1, key);
    if (i != -1) {
        cout << "\nKey Found at Index\t:\t" << i << endl;
    }
    else {
        cout << "\nKey not found\n";
    }
    return 0;
}
