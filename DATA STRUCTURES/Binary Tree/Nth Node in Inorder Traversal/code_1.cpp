/
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
    void NthNodeInorder(bnode* , int);
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
    int n;
    cout << "\nEnter Value of N\t:\t";
    cin >> n;
    cout << "\nNth Node in Inorder\t\t\t:\t";
    NthNodeInorder(root , n);
}

void btree::NthNodeInorder(bnode* node, int n) {
    static int count = 0;
    if (node == NULL) {
        return;
    }
    
    if (count <= n) {
        NthNodeInorder(node->left, n);
        count++;
        if (count == n) {
            cout << node->data << endl;
        }
        NthNodeInorder(node->right, n);
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}

