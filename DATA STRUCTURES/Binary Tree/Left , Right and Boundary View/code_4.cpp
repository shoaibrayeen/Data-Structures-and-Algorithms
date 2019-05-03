//
//  code_4.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <unordered_set>
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
    void rightView(bnode*);
    void rightViewUtil(bnode*,int,int*);
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
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
}


void btree::display() {
    insert();
    cout << "\nRight View\t:\t";
    rightView(root);
    cout << endl;
}

void btree::rightViewUtil(bnode *root, int level, int *max_level) {
    if (root==NULL) {
        return;
    }
    if (*max_level < level) {
        cout << root->data << "\t";
        *max_level = level;
    }
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

void btree::rightView(bnode *root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
