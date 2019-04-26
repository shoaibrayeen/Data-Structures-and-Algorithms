//
//  code_1.cpp
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
    bnode* findDistUtil(bnode*, int, int, int &,int &, int &, int);
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

bnode* btree::findDistUtil(bnode* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1) {
        d1 = lvl;
        return root;
    }
    if (root->data == n2) {
        d2 = lvl;
        return root;
    }
    bnode *left_lca  = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
    bnode *right_lca = findDistUtil(root->right, n1, n2,  d1, d2, dist, lvl+1);
    if (left_lca && right_lca) {
        dist = d1 + d2 - 2*lvl;
        return root;
    }
    return (left_lca != NULL)? left_lca: right_lca;
}

int btree::findDistance(bnode *root, int n1, int n2) {
    int d1 = -1, d2 = -1, dist;
    bnode *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);
    if (d1 != -1 && d2 != -1) {
        return dist;
    }
    if (d1 != -1) {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
    if (d2 != -1) {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
    
    return -1;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
