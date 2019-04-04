//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
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
    void preorder(bnode*);
    void postorder(bnode*);
    void inorder(bnode*);
    int heighAndSize(bnode* , int &);
    float density(bnode*);
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
    cout << "\nInorder\t\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t\t:\t";
    postorder(root);
    cout << "\nPreorder\t\t:\t";
    preorder(root);
    cout << "\nDensity\t:\t" << density(root);
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



int btree::heighAndSize(bnode* node, int &size) {
    if (node==NULL) {
        return 0;
    }
    int l = heighAndSize(node->left, size);
    int r = heighAndSize(node->right, size);
    size++;
    return (l > r) ? l + 1 : r + 1;
}

float btree::density(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int size = 0;
    int _height = heighAndSize(root, size);
    
    return (float)size/_height;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}

