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
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    bool isLeaf(bnode*);
    int leftLeavesSum(bnode*);
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
    cout << "\nSum of Left Leaves\t:\t" << leftLeavesSum(root);
}

bool btree::isLeaf(bnode *node) {
    if (node == NULL) {
        return false;
    }
    if (node->left == NULL && node->right == NULL) {
        return true;
    }
    return false;
}

int btree::leftLeavesSum(bnode *root) {
    int res = 0;
    if (root != NULL) {
        if (isLeaf(root->left)) {
            res += root->left->data;
        }
        else {
            res += leftLeavesSum(root->left);
        }
        res += leftLeavesSum(root->right);
    }
    return res;
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
