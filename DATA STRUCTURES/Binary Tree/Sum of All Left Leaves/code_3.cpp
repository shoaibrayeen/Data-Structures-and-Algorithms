
//  code_3.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
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
    int leftLeavesSum(bnode*);
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
    cout << "\nSum of Left Leaves\t:\t" << leftLeavesSum(root);
}

int btree::leftLeavesSum(bnode *root ) {
    if (!root) {
        return 0;
    }
    stack<bnode*> s;
    s.push(root);
    bnode* curr;
    int sum = 0;
    while(!s.empty()) {
        curr = s.top();
        s.pop();
        if ( curr->left != NULL) {
            s.push(curr->left);
            if( curr->left->left == NULL && curr->left->right == NULL) {
                sum += curr->left->data;
            }
        }
        if ( curr->right != NULL) {
            s.push(curr->right);
        }
    }
    return sum;
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
