//
//  code_2.cpp
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
    void preorder(bnode*);
    void preorderIterative(bnode*);
    void preorderMorris(bnode*);
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
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9);
}
void btree::display() {
    insert();
    cout << "\nRecusive Preorder\t\t:\t";
    preorder(root);
    cout << "\nIterative Preorder\t\t:\t";
    preorderIterative(root);
    cout << "\nMorris Preorder\t\t\t:\t";
    preorderMorris(root);
}

void btree :: preorder(bnode* root) {
    if (!root) {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}

void btree:: preorderIterative(bnode* root) {
    stack<bnode *> s;
    s.push(root);
    bnode* curr;
    while (!s.empty()) {
        curr = s.top();
        s.pop();
        cout << curr->data << "\t";
        if ( curr->right) {
            s.push(curr->right);
        }
        if ( curr->left) {
            s.push(curr->left);
        }
    }
}

void btree::preorderMorris(bnode * root) {
    while (root) {
        if (root->left == NULL) {
            cout << root->data << "\t";
            root = root->right;
        }
        else {
            bnode* current = root->left;
            while (current->right && current->right != root) {
                current = current->right;
            }
            if (current->right == root) {
                current->right = NULL;
                root = root->right;
            }
            else {
                cout << root->data << "\t";
                current->right = root;
                root = root->left;
            }
        }
    }
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
