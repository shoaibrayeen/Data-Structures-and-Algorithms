//
//  code_2.cpp
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

bool btree::isSumTree(bnode *root) {
    int ls , rs;
    if ( root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }
    if( isSumTree(root->left) && isSumTree(root->right)) {
        if( root->left == NULL) {
            ls = 0;
        }
        else if((root->left->left == NULL && root->left->right == NULL)) { //checking leaf
            ls = root->left->data;
        }
        else {
            ls = 2 * (root->left->data);
        }
        if( root->right == NULL) {
            rs = 0;
        }
        else if( (root->right->left == NULL && root->right->right == NULL)) { //checking leaf
            rs = root->right->data;
        }
        else {
            rs = 2*(root->right->data);
        }
        return(root->data == ls + rs);
    }
    
    return false;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
