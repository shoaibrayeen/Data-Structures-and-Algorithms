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
    void inorder(bnode*);
    bnode* newNode(int);
    bnode* buildTree(int in[], int level[], int inStrt, int inEnd , int m);
    int search(int arr[], int strt, int end, int value);
    int *extrackKeys(int in[], int level[], int m, int n);
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
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    root = buildTree(in, level, 0, n - 1, n);
    cout << "\nInorder\t:\t";
    inorder(root);
    
}

void btree::inorder(bnode * root) {
    if (root) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

bnode* btree::buildTree(int in[], int level[], int inStrt, int inEnd , int n) {
    if (inStrt > inEnd) {
        return NULL;
    }
    bnode *root = newNode(level[0]);
    if (inStrt == inEnd) {
        return root;
    }
    int inIndex = search(in, inStrt, inEnd, root->data);
    int *llevel  = extrackKeys(in, level, inIndex, n);
    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n);
    root->left = buildTree(in, llevel, inStrt, inIndex-1, n);
    root->right = buildTree(in, rlevel, inIndex+1, inEnd, n);
    delete [] llevel;
    delete [] rlevel;
    
    return root;
}

int btree::search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int *btree::extrackKeys(int in[], int level[], int m, int n) {
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++) {
        if (search(in, 0, m-1, level[i]) != -1) {
            newlevel[j] = level[i], j++;
        }
    }
    return newlevel;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
