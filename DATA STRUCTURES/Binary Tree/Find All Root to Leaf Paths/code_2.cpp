//
//  code_2.cpp
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
    void printPathsRecur(bnode* , int*, int);
    void printRootToLeaf(bnode*);
    void printPath(int* ,int);
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
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
}


void btree::display() {
    
    insert();
    cout << "\nAll root to Leaf Path\n";
    printRootToLeaf(root);
}

void btree::printPathsRecur(bnode* node, int *path , int pathLen) {
    if (node == NULL) {
        return;
    }
    path[pathLen] = node->data;
    pathLen++;
    if (node->left == NULL && node->right == NULL) {
        printPath(path, pathLen);
    }
    else {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

void btree::printRootToLeaf(bnode* root) {
    int path[1000];
    printPathsRecur(root, path, 0);
}

void btree::printPath(int *path, int len) {
    for (int i = 0; i < len; i++) {
        cout << path[i] << "\t";
    }
    cout<<endl;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
