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
    bnode *root , *root1;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    bool isIdentical(bnode* ,bnode*);
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
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
    
    root1 = newNode(1);
    root1->left = newNode(-2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(-6);
    root1->right->right = newNode(2);
}
void btree::display() {
    
    insert();
    if(isIdentical(root , root1)) {
        cout << "\nBoth are identical.\n";
        return;
    }
    cout << "\nBoth are different Trees.\n";
}



bool btree::isIdentical(bnode *root , bnode* root1) {
    if (root == NULL && root1 == NULL) {
        return true;
    }
    if (root != NULL && root1 != NULL) {
        return root->data == root1->data   && isIdentical(root->left, root1->left) && isIdentical(root->right, root1->right);
    }
    return false;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
