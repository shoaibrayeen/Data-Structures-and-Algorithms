//
//  code_2.cpp
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
    int size(bnode*);
};
btree::btree() {
    
    root = NULL;
}
bnode* btree:: newNode(int value) {
    
    bnode* temp = new bnode;
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
}


void btree::display() {
    insert();
    cout << "\nSize of Tree\t:\t" << size(root);
    cout << endl;
}



int btree::size(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    queue<bnode*> q;
    q.push(root);
    int count = 1;
    while (!q.empty()) {
        bnode* temp = q.front();
        q.pop();
        if (temp != NULL) {
            if (temp->left != NULL ) {
                count++;
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                count++;
                q.push(temp->right);
            }
        }
    }
    return count;
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
