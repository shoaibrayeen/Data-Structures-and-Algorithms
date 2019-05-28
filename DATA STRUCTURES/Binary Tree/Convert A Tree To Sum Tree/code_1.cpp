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
    void inorder(bnode*);
    int convertToSumTree(bnode*);
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
    root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
}

void btree::display() {
    insert();
    convertToSumTree(root);
    cout << "\nInorder of Sum Tree\t:\t";
    inorder(root);
}

int btree::convertToSumTree(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    int temp = root->data;
    root->data = convertToSumTree(root->left) + convertToSumTree(root->right);
    return root->data + temp;
}

void btree::inorder(bnode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
