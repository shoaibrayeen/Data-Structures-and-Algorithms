//
//  code_3.cpp
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
    void leftView(bnode*);
    void leftViewUtil(bnode*,int,int*);
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
    root              = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(8);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(9);
    root->right->right = newNode(10);
}


void btree::display() {
    insert();
    cout << "\nLeft View\t:\t";
    leftView(root);
    cout << endl;
}

void btree::leftViewUtil(bnode *root, int level, int *max_level) {
    if (root==NULL) {
        return;
    }
    if (*max_level < level) {
        cout << root->data << "\t";
        *max_level = level;
    }
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}

void btree::leftView(bnode *root) {
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
