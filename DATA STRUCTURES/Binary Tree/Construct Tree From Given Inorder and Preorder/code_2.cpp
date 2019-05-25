//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <unordered_map>
using namespace std;
 
struct bnode {
    char data;
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
    bnode* buildTree(char in[], char pre[], int inStrt, int inEnd , unordered_map<char, int>& m);
    bnode* buildTreeWrap(char in[], char pre[], int len);
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
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    root = buildTreeWrap(in, pre, len);
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

bnode* btree::buildTree(char in[], char pre[], int inStrt, int inEnd , unordered_map<char, int>& m) {
    static int preIndex = 0;
    
    if (inStrt > inEnd) {
        return NULL;
    }
    char curr = pre[preIndex++];
    struct bnode* tNode = newNode(curr);
    if (inStrt == inEnd) {
        return tNode;
    }
    int inIndex = m[curr];
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, m);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, m);
    
    return tNode;
}

bnode* btree::buildTreeWrap(char in[], char pre[], int len) {
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++) {
        mp[in[i]] = i;
    }
    return buildTree(in, pre, 0, len - 1, mp);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
