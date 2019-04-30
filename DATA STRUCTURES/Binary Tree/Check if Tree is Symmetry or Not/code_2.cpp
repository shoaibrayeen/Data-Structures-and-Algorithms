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



bool btree::isSymmetry(bnode* root ) {
    if(root == NULL) {
        return true;
    }
    if(!root->left && !root->right) {
        return true;
    }
    queue <bnode*> q;
    q.push(root);
    q.push(root);
    bnode* leftNode, *rightNode;
    while(!q.empty()){
        leftNode = q.front();
        q.pop();
        
        rightNode = q.front();
        q.pop();
        if( leftNode->data != rightNode->data) {
            return false;
        }
        if(leftNode->left && rightNode->right) {
            q.push(leftNode->left);
            q.push(rightNode->right);
        }
        else if (leftNode->left || rightNode->right) {
            return false;
        }
        if(leftNode->right && rightNode->left) {
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        else if(leftNode->right || rightNode->left) {
            return false;
        }
    }
    
    return true;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
