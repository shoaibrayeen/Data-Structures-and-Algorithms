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
    bnode* binaryToList(bnode*);
    bnode* binaryToListUtil(bnode* root);
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
    bnode* node = binaryToList(root);
    cout << "\nLinked List\t:\t";
    while (node != NULL) {
        cout << node->data << "\t";
        node = node->right;
    }
    cout << endl;
}

bnode* btree::binaryToListUtil(bnode* root) {
    if (root == NULL) {
        return root;
    }
    if (root->left != NULL) {
        bnode* left = binaryToListUtil(root->left);
        for (; left->right != NULL; left = left->right);
        left->right = root;
        root->left = left;
    }
    if (root->right != NULL) {
        bnode* right = binaryToListUtil(root->right);
        for (; right->left != NULL; right = right->left);
        right->left = root;
        root->right = right;
    }
    
    return root;
}

bnode* btree::binaryToList(bnode* root) {
    if (root == NULL) {
        return root;
    }
    root = binaryToListUtil(root);
    while (root->left != NULL) {
        root = root->left;
    }
    return (root);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
