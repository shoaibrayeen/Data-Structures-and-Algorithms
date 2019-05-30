//
//  code_2.cpp
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
    int height(bnode*);
    void deepestNode(bnode *root , int);
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
    cout << "\nDeepest Node\t:\t";
    deepestNode(root , height(root));
}

void btree::deepestNode(bnode *root , int levels) {
    if(!root) {
        return;
    }
    if(levels == 1) {
        cout << root->data;
    }
    else if(levels > 1) {
        deepestNode(root->left, levels - 1);
        deepestNode(root->right, levels - 1);
    }
}

int btree::height(bnode * root) {
    if(!root) {
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    return max(leftHt, rightHt) + 1;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
