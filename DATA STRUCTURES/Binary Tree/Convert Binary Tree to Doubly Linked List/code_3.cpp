//
//  code_3.cpp
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
    void binaryToList(bnode*,bnode**);
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
    bnode* node;
    binaryToList(root , &node);
    cout << "\nLinked List\t:\t";
    while (node != NULL) {
        cout << node->data << "\t";
        node = node->right;
    }
    cout << endl;
}

                      
void btree::binaryToList(bnode* root , bnode** head) {
    if (root == NULL) {
        return;
    }
    static bnode* prev = NULL;
    binaryToList(root->left, head);
    if (prev == NULL) {
        *head = root;
    }
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    binaryToList(root->right, head);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
