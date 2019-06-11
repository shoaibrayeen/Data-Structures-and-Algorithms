//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include <stack>
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
    int sumNodes(bnode*);
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

int btree::sumNodes(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    stack<bnode*> s;
    s.push(root);
    int sum = 0;
    while(!s.empty()) {
        root = s.top();
        s.pop();
        sum += root->data;
        if ( root->left) {
            s.push(root->left);
        }
        if ( root->right) {
            s.push(root->right);
        }
    }
    return sum;
}

void btree:: insert() {
    root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
}
void btree::display() {
    insert();
    cout << "\nSum of All Nodes\t:\t" << sumNodes(root);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
