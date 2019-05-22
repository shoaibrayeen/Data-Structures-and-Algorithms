//
//  code_1.cpp
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
    bnode *root, *root1;
    btree();
    void insert();
    void display();
    void inorder(bnode*);
    bnode* newNode(int);
    bnode* Merge(bnode* , bnode*);
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
    
    root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->right = newNode(6);
}

void btree::display() {
    insert();
    bnode* res =  Merge(root, root1);
    cout << "\nInorder of Merge Tree\t:\t";
    inorder(res);
    
}

void btree::inorder(bnode * root) {
    if (root) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

bnode *btree::Merge(bnode * t1, bnode * t2) {
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    t1->data += t2->data;
    t1->left = Merge(t1->left, t2->left);
    t1->right = Merge(t1->right, t2->right);
    return t1;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
