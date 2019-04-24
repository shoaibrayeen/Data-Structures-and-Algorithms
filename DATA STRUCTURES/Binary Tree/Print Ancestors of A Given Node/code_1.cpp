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
    bool printAncestors(bnode* , int);
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
    root->left->right->left = newNode(8);
    root->right->left->right = newNode(9);
}


void btree::display() {
    
    insert();
    int n;
    cout << "\nEnter Node\t:\t";
    cin >> n;
    cout << "\nAncestors\t:\t";
    printAncestors(root, n);
}

bool btree::printAncestors(bnode *root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->data == target) {
        return true;
    }
    if ( printAncestors(root->left, target) || printAncestors(root->right, target) ) {
        cout << root->data << "\t";
        return true;
    }
    return false;
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
