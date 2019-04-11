//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;
int findDepthRec(string tree, int n, int& index) {
    if (index >= n || tree[index] == 'L') {
        return 0;
    }
    index++;
    int left = findDepthRec(tree, n, index);
    index++;
    int right = findDepthRec(tree, n, index);
    
    return max(left, right) + 1;
}

int findDepth(string str) {
    int index = 0;
    int n = int(str.length());
    return findDepthRec(str, n, index);
}

int main() {
    string str;
    cout << "\nEnter Preorder N for Node and L for Leave\t:\t";
    cin >> str;
    cout << "\nDepth of Tree\t:\t" << findDepth(str) << endl;
    return 0;
}
