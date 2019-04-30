//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <stack>
#include <map>
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
    bool isMirror(bnode*,bnode*);
    bool isSymmetry(bnode*);
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
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);
}


void btree::display() {
    insert();
    if(isSymmetry(root)) {
        cout << "\nTree is Symmetry.\n";
        return;
    }
    cout << "\nTree is not Symmetry.\n";
}

bool btree::isMirror(bnode *root1, bnode *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 && root2 && root1->data == root2->data) {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    return false;
}

bool btree::isSymmetry(bnode* root ) {
    return isMirror(root, root);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
