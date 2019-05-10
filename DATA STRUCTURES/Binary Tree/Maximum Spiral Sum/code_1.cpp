//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct bnode {
    int data;
    int hd;
    bnode *left;
    bnode *right;
};

class btree {
public:
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    int maxSpiralSum(bnode*);
    int maxSum(vector<int>);
};
btree::btree() {
    
    root = NULL;
}
bnode* btree:: newNode(int value) {
    
    bnode* temp=new bnode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void btree:: insert() {
    root = newNode(-2);
    root->left = newNode(-3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(1);
    root->right->left = newNode(-2);
    root->right->right = newNode(-1);
    root->left->left->left = newNode(-3);
    root->right->right->right = newNode(2);
}


void btree::display() {
    insert();
    cout << "\nMaximum Spiral Sum\t:\t" << maxSpiralSum(root);
    cout << endl;
}

int btree::maxSpiralSum(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    stack<bnode*> s1;
    stack<bnode*> s2;
    vector<int> arr;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            bnode* temp = s1.top();
            s1.pop();
            arr.push_back(temp->data);
            if (temp->right) {
                s2.push(temp->right);
            }
            if (temp->left) {
                s2.push(temp->left);
            }
        }
        while (!s2.empty()) {
            bnode* temp = s2.top();
            s2.pop();
            arr.push_back(temp->data);
            if (temp->left) {
                s1.push(temp->left);
            }
            if (temp->right) {
                s1.push(temp->right);
            }
        }
    }
    return maxSum(arr);
    
}

int btree::maxSum(vector<int> arr) {
    int n = int(arr.size());
    int max_ending_here = INT_MIN;
    int max_so_far = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (max_ending_here < 0) {
            max_ending_here = arr[i];
        }
        else {
            max_ending_here += arr[i];
        }
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
