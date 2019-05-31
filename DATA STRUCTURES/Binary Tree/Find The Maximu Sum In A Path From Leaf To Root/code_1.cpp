//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
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
    void maxSumPath(bnode* Node);
    bool printPath(bnode* root, bnode* target_leaf);
    void getTargetLeaf(bnode* Node, int* max_sum_ref,int curr_sum, bnode** target_leaf_ref);
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
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(17);
}

void btree::display() {
    insert();
    maxSumPath(root);
}

bool btree::printPath(bnode* root, bnode* target_leaf) {
    if (root == NULL) {
        return false;
    }
    if (root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf)) {
        cout << root->data << "\t";
        return true;
    }
    
    return false;
}

void btree::getTargetLeaf(bnode* Node, int* max_sum_ref,int curr_sum, bnode** target_leaf_ref) {
    if (Node == NULL) {
        return;
    }
    curr_sum = curr_sum + Node->data;
    if (Node->left == NULL && Node->right == NULL) {
        if (curr_sum > *max_sum_ref) {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = Node;
        }
    }
    getTargetLeaf(Node->left, max_sum_ref, curr_sum, target_leaf_ref);
    getTargetLeaf(Node->right, max_sum_ref, curr_sum, target_leaf_ref);
}

void btree::maxSumPath(bnode* Node) {
    if (Node == NULL) {
        return;
    }
    bnode* target_leaf;
    int max_sum = INT_MIN;
    getTargetLeaf(Node, &max_sum, 0, &target_leaf);
    cout << "\nPath From Leaf To Root\t:\t";
    printPath(Node, target_leaf);
    cout << "\nMaximum Sum\t:\t" << max_sum;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
