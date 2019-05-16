//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <stack>
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
    void preorder(bnode*);
    void postorder(bnode*);
    void inorder(bnode*);
    void inorderIterative(bnode*);
    void inorderMorris(bnode*);
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
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9);
}
void btree::display() {
    insert();
    cout << "\nRecusive Inorder\t\t:\t";
    inorder(root);
    cout << "\nIterative Inorder\t\t:\t";
    inorderIterative(root);
    cout << "\nMorris Inorder\t\t\t:\t";
    inorderMorris(root);
}

void btree :: inorder(bnode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

void btree:: inorderIterative(bnode* root) {
    stack<bnode *> s;
    bnode *curr = root;
    
    while (curr != NULL || s.empty() == false) {
        while (curr !=  NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << "\t";
        curr = curr->right;
        
    }
}
void btree::inorderMorris(bnode * root) {
    bnode *current, *pre;
    
    if (root == NULL) {
        return;
    }
    current = root;
    while (current != NULL) {
        
        if (current->left == NULL) {
            cout << current->data << "\t";
            current = current->right;
        }
        else {
            pre = current->left;
            while (pre->right != NULL && pre->right != current) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            else {
                pre->right = NULL;
                cout << current->data << "\t";
                current = current->right;
            }
        }
    }
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
