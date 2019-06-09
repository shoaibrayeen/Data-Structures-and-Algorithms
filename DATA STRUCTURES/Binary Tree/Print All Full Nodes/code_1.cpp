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
    void findFullNode(bnode*);
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
    cout << "\nFull Nodes\t:\t";
    findFullNode(root);
    cout << endl;
}


void btree::findFullNode(bnode *root) {
    if (root != NULL) {
        findFullNode(root->left);
        if (root->left != NULL && root->right != NULL) {
            cout << root->data << "\t";
        }
        findFullNode(root->right);
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
