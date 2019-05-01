//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <unordered_set>
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
    bool checkDup(bnode*);
    bool checkDupUtil(bnode* , unordered_set<int> &);
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
    if(checkDup(root)) {
        cout << "\nTree Contains Duplicated.\n";
        return;
    }
    cout << "\nTree does not contains Duplicated.\n";
}



bool btree::checkDupUtil(bnode* root, unordered_set<int> &s) {
    if (root == NULL) {
        return false;
    }
    if (s.find(root->data) != s.end()) {
        return true;
    }
    s.insert(root->data);
    return checkDupUtil(root->left, s) || checkDupUtil(root->right, s);
}

bool btree::checkDup(bnode* root ) {
    unordered_set<int> s;
    return checkDupUtil(root, s);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
