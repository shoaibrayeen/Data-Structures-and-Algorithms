//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

struct bnode {
    int data;
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
    int findLargestSubtreeSum(bnode*);
    int findLargestSubtreeSumUtil(bnode* , int&);
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
    /*
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);
     */
    root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
}
void btree::display() {
    
    insert();
    cout << "\nLargest Subtree Sum\t:\t" << findLargestSubtreeSum(root);
}


int btree::findLargestSubtreeSumUtil(bnode* root, int& ans) {
    if (root == NULL) {
        return 0;
    }
    int currSum = root->data + findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right, ans);
    ans = max(ans, currSum);
    return currSum;
}

int btree::findLargestSubtreeSum(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    int ans = INT_MIN;
    findLargestSubtreeSumUtil(root, ans);
    return ans;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
