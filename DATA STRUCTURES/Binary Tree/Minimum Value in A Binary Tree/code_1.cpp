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
    int minimum(bnode* );
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
    root = newNode(12);
    root->left = newNode(21);
    root->right = newNode(31);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(1);
}


void btree::display() {
    
    insert();
    cout << "\nMinimum Node\t:\t" << minimum(root);
}

int btree::minimum(bnode* root) {
    if (!root) {
        return 0;
    }
    static int minNode = root->data;
    if ( root->left ) {
        minNode = min (minNode , root->left->data);
        minNode = min ( minNode , minimum(root->left));
    }
    if ( root->right ) {
        minNode = min (minNode , root->right->data);
        minNode = min ( minNode , minimum(root->right));
    }
    return minNode;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
