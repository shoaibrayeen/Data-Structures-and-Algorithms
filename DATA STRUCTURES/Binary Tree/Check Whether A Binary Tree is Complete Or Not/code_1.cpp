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
    bool isComplete(bnode*);
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
}
void btree::display() {
    
    insert();
    if(isComplete(root)) {
        cout << "\nBinary Tree is Complete\n";
        return;
    }
    cout << "\nBinary Tree is not Complete\n";
}



bool btree::isComplete(bnode *root) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if ((root->left) && (root->right)) {
        return (isComplete(root->left) && isComplete(root->right));
    }
    return false;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
