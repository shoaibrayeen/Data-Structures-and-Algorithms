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
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    bnode* LCA(bnode*, int, int);
    int findLevel(bnode* , int, int);
    int findDistance(bnode*,int, int);
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
}


void btree::display() {
    
    insert();
    int n;
    cout << "\nEnter 1st Node\t:\t";
    cin >> n;
    int k;
    cout << "\nEnter 2nd Node\t:\t";
    cin >> k;
    cout << "\nDistance Between them\t:\t" << findDistance(root, n, k) << endl;
}
int btree::findLevel(bnode *root, int k, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == k) {
        return level;
    }
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}

bnode* btree::LCA(bnode * root, int n1,int n2) {
    if (root == NULL) {
        return root;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    bnode* left = LCA(root->left, n1, n2);
    bnode* right = LCA(root->right, n1, n2);
    
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL) {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int btree::findDistance(bnode *root, int a, int b) {
    bnode* lca = LCA(root, a , b);
    
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
    
    return d1 + d2;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
