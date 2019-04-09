//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

int search(int arr[], int l, int h, int key) {
    for(int i = l; i <= h; i++ ) {
        if(arr[i] == key ) {
            return i;
        }
    }
    return -1;
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
