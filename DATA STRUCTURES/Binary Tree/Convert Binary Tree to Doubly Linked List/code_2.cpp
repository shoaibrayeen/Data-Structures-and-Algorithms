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
    bnode* binaryToList(bnode*);
    bnode* fixNextPtr(bnode*);
    void fixPrevPtr(bnode*);
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
    root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);
}

void btree::display() {
    insert();
    bnode* node = binaryToList(root);
    cout << "\nLinked List\t:\t";
    while (node != NULL) {
        cout << node->data << "\t";
        node = node->right;
    }
    cout << endl;
}

void btree:: fixPrevPtr(bnode *root) {
    static bnode *pre = NULL;
    if (root != NULL) {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}

bnode* btree::fixNextPtr(bnode* root) {
    bnode *prev = NULL;
    while (root && root->right != NULL) {
        root = root->right;
    }
    while (root && root->left != NULL) {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return (root);
}

                      
bnode* btree::binaryToList(bnode* root) {
    fixPrevPtr(root);
    return fixNextPtr(root);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
