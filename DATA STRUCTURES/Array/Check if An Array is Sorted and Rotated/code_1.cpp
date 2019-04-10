//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

void checkIfSortRotated(int arr[], int n) {
    int minEle = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minEle) {
            minEle = arr[i];
            minIndex = i;
        }
    }
    
    int flag1 = 1;
    for (int i = 1; i < minIndex; i++) {
        if (arr[i] < arr[i - 1]) {
            flag1 = 0;
            break;
        }
    }
    
    int flag2 = 1;
    for (int i = minIndex + 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            flag2 = 0;
            break;
        }
    }
    if (flag1 && flag2 && (arr[n - 1] < arr[0])) {
        cout << "\nArray is Sorted and Rotated\n";
    }
    else {
        cout << "\nArray is not Rotated\n";
    }
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
    checkIfSortRotated(array, n);
    cout << endl;
    return 0;
}
