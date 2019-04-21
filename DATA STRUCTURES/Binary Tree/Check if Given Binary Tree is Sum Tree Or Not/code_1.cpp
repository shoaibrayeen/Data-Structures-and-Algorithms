//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <queue>
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
    int sum(bnode*);
    bool isSumTree(bnode*);
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
    root               = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
}
void btree::display() {
    
    insert();
    if(isSumTree(root)) {
        cout << "\nIt's Sum Tree.\n";
        return;
    }
    cout << "\nIt's not Sum Tree.\n";
}

int btree::sum(bnode *root) {
    if(root == NULL) {
        return 0;
    }
    return sum(root->left) + root->data + sum(root->right);
}

bool btree::isSumTree(bnode *root) {
    if( root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }
    if((root->data == sum(root->left) + sum(root->right) ) && isSumTree(root->left) && isSumTree(root->right)) {
        return true;
    }
    return false;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
