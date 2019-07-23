//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//

int preIndex = 0;
void helper(int *in, int *pre , int s, int e , unordered_map<int,int> m) {
    if (s > e) {
        return;
    }
    int inIndex = m.find(pre[preIndex++])->second;
    helper(in, pre, s, inIndex - 1, m);
    helper(in, pre, inIndex + 1, e, m);
    cout << in[inIndex] << "\t";
}

void printPost(int* in, int * pre) {
    unordered_map <int, int> m;
    for(int i = 0; i < 6; i++ ) {
        m[in[i]] = i;
    }
    helper(in, pre, 0, 5, m);
}

int main() {

    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    cout << "\nPostOrder\t:\t";
    printPost(in , pre);
    cout << "\n";
    return 0;
}
