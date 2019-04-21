//
//  code_1.cpp
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
    bool isSameLevel(bnode*);
    bool isSameLevelUtil(bnode*,int ,int*);
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

bool btree::isSameLevelUtil(bnode *root, int level, int *leafLevel) {
    if (root == NULL) {
        return true;
    }
    if (root->left == NULL && root->right == NULL) {
        if (*leafLevel == 0) {
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }
    return isSameLevelUtil(root->left, level + 1, leafLevel) && isSameLevelUtil(root->right, level + 1, leafLevel);
}
void btree::display() {
    
    insert();
    if(isSameLevel(root)) {
        cout << "\nAll Leaves are at same level.\n";
        return;
    }
    cout << "\nAll leaver are at different level\n";
}

bool btree::isSameLevel(bnode *root) {
    int level = 0, leafLevel = 0;
    return isSameLevelUtil(root, level, &leafLevel);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
