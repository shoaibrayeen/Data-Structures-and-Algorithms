//
//  code_4.cpp
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
    bnode* node = NULL;
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
    binaryToList(root->right, head);
    root->right = *head;
    if (*head != NULL) {
        (*head)->left = root;
    }
    *head = root;
    binaryToList(root->left, head);
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
