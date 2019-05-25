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
    bnode* buildTree(char in[], char pre[], int inStrt, int inEnd);
    int search(char arr[], int strt, int end, char value);
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
    root = buildTree(in, pre, 0, len - 1);
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

bnode* btree::buildTree(char in[], char pre[], int inStrt, int inEnd) {
    static int preIndex = 0;
    if (inStrt > inEnd) {
        return NULL;
    }
    bnode* tNode = newNode(pre[preIndex++]);
    if (inStrt == inEnd) {
        return tNode;
    }
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    
    return tNode;
}

int btree::search(char arr[], int strt, int end, char value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
