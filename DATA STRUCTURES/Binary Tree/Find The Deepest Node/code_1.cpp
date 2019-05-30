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
    void find(bnode* root , int level, int &maxLevel, int &res);
    int deepestNode(bnode *root);
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
    cout << "\nDeepest Node\t:\t" << deepestNode(root);
}

int btree::deepestNode(bnode *root) {
    int res = -1;
    int maxLevel = -1;
    find(root, 0, maxLevel, res);
    return res;
}

void btree::find(bnode* root , int level, int &maxLevel, int &res) {
    if (root != NULL) {
        find(root->left, ++level, maxLevel, res);
        if (level > maxLevel) {
            res = root->data;
            maxLevel = level;
        }
        find(root->right, level, maxLevel, res);
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
