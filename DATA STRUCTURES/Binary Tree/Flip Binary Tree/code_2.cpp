//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
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
    void levelOrder(bnode*);
    bnode* flipBinaryTree(bnode* root);
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
    cout << "\nLevel Order Before Flipping\t:\t";
    levelOrder(root);
    bnode* node = flipBinaryTree(root);
    cout << "\nLevel Order After Flipping\t:\t";
    levelOrder(node);
}

bnode* btree::flipBinaryTree(bnode* root) {
    bnode *curr = root;
    bnode *next = NULL;
    bnode *temp = NULL;
    bnode *prev = NULL;
    while(curr) {
        next = curr->left;
        curr->left = temp;
        temp = curr->right;
        curr->right = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void btree::levelOrder(bnode* root) {
    if (root == NULL) {
        return;
    }
    queue<bnode *> q;
    q.push(root);
    
    while (!q.empty()) {
        root = q.front();
        q.pop();
        cout << root->data << "\t";
        if ( root->left) {
            q.push(root->left);
        }
        if ( root->right) {
            q.push(root->right);
        }
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
