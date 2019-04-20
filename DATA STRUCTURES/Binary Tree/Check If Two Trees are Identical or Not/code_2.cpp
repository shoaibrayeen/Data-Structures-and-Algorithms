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
    bnode *root , *root1;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    bool isIdentical(bnode* ,bnode*);
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
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
    
    root1 = newNode(1);
    root1->left = newNode(-2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(-6);
    root1->right->right = newNode(2);
}
void btree::display() {
    
    insert();
    if(isIdentical(root , root1)) {
        cout << "\nBoth are identical.\n";
        return;
    }
    cout << "\nBoth are different Trees.\n";
}



bool btree::isIdentical(bnode *root , bnode* root1) {
    if (!root1  && !root) {
        return true;
    }
    if (!root1 || !root) {
        return false;
    }
    queue<bnode *> q1, q2;
    q1.push(root);
    q2.push(root1);
    
    while (!q1.empty() && !q2.empty()) {
        bnode *n1 = q1.front();
        bnode *n2 = q2.front();
        
        if (n1->data != n2->data) {
            return false;
        }
        q1.pop();
        q2.pop();
        if (n1->left && n2->left) {
            q1.push(n1->left);
            q2.push(n2->left);
        }
        else if (n1->left || n2->left) {
            return false;
        }
        if (n1->right && n2->right) {
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if (n1->right || n2->right) {
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
