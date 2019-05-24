//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <unordered_set>
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
    void display();
    void inorder(bnode*);
    bnode* newNode(int);
    bnode* buildTree(int in[], int level[], int inStrt, int inEnd , int m);
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

bnode* btree::buildTree(int inorder[], int levelOrder[], int iStart, int iEnd , int n) {
    if (n <= 0) {
        return NULL;
    }
    bnode* root = newNode(levelOrder[0]);
    int index = -1;
    for (int i = iStart; i <= iEnd; i++) {
        if (levelOrder[0] == inorder[i]) {
            index = i;
            break;
        }
    }
    unordered_set<int> s;
    for (int i = iStart; i < index; i++ ) {
        s.insert(inorder[i]);
    }
    int lLevel[s.size()];  // Left
    int rLevel[iEnd-iStart-s.size()]; // Right
    int li = 0, ri = 0;
    for (int i = 1; i < n; i++) {
        if (s.find(levelOrder[i]) != s.end()) {
            lLevel[li++] = levelOrder[i];
        }
        else {
            rLevel[ri++] = levelOrder[i];
        }
    }
    root->left = buildTree(inorder, lLevel, iStart, index-1, index-iStart);
    root->right = buildTree(inorder, rLevel, index+1, iEnd, iEnd-index);
    return root;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
