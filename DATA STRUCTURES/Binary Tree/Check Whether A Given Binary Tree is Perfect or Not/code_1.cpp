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
    int getDepth(bnode*);
    bool isPerfect(bnode*);
    bool isPerfectUtil(bnode*,int ,int);
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
    //root->right->right = newNode(2);
}
void btree::display() {
    
    insert();
    if(isPerfect(root)) {
        cout << "\nBinary Tree is Perfect\n";
        return;
    }
    cout << "\nBinary Tree is not Perfect\n";
}

int btree::getDepth(bnode *node) {
    int d = 0;
    while (node != NULL) {
        d++;
        node = node->left;
    }
    return d;
}

bool btree::isPerfectUtil(bnode* root, int d, int level = 0) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return (d == level+1);
    }
    if (root->left == NULL || root->right == NULL) {
        return false;
    }
    return isPerfectUtil(root->left, d, level+1) && isPerfectUtil(root->right, d, level+1);
}

bool btree::isPerfect(bnode *root) {
    int depth = getDepth(root);
    return isPerfectUtil(root, depth);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
