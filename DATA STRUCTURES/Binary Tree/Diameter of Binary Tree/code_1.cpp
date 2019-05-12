//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <map>
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
    int diameter(bnode*);
    int height(bnode*);
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
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
}


void btree::display() {
    insert();
    cout << "\nDiameter of Tree\t:\t" << diameter(root);
    cout << endl;
}

int btree::diameter(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int btree::height(bnode* node) {
    if(node == NULL) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
