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
    void postorder(bnode*);
    void inorder(bnode*);
    void printSpiral(bnode*);
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
    /*
    root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
     */
}
void btree::display() {
    
    insert();
    cout << "\nInorder\t\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t\t:\t";
    postorder(root);
    cout << "\nPreorder\t\t:\t";
    preorder(root);
    cout << "\nLevel Order in Spiral Form\t:\t";
    printSpiral(root);
}
void btree :: postorder(bnode* root) {
    
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void btree :: preorder(bnode* root) {
    
    if (root == NULL) {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void btree :: inorder(bnode* root) {
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}


void btree::printSpiral(struct bnode* root)
{
    if (root == NULL) {
        return;
    }
    stack<struct bnode*> s1; // For levels to be printed from right to left
    stack<struct bnode*> s2; // For levels to be printed from left to right
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            struct bnode* temp = s1.top();
            s1.pop();
            cout << temp->data << "\t";
            if (temp->right) {
                s2.push(temp->right);
            }
            if (temp->left) {
                s2.push(temp->left);
            }
        }
        while (!s2.empty()) {
            struct bnode* temp = s2.top();
            s2.pop();
            cout << temp->data << "\t";
            if (temp->left) {
                s1.push(temp->left);
            }
            if (temp->right) {
                s1.push(temp->right);
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
