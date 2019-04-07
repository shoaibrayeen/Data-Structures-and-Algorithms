
//
//  code_2.cpp
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
    bnode *root , *root2;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    bool checkMirror(bnode* , bnode*);
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
    /*root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    */
    
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
    root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(5);
    root2->right->right = newNode(4);
}
void btree::display() {
    
    insert();
    if(checkMirror(root, root2)) {
        cout << "\nOne is Mirror of Another\n";
    }
    else {
        cout << "\nBoth are different Tree\n";
    }
}

bool btree::checkMirror(bnode* root1, bnode* root2) {
    stack <bnode*> st1, st2;
    while (true) {
        while (root1 && root2) {
            if (root1->data != root2->data) {
                return false;
            }
            
            st1.push(root1);
            st2.push(root2);
            root1 = root1->left;
            root2 = root2->right;
        }
        if (!(root1 == NULL && root2 == NULL)) {
            return false;
        }
        
        if (!st1.empty() && !st2.empty()) {
            root1 = st1.top();
            root2 = st2.top();
            st1.pop();
            st2.pop();
            root1 = root1->right;
            root2 = root2->left;
        }
        else {
            break;
        }
    }
    return true;
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
