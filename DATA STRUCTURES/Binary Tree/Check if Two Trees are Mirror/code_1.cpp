
//
//  code_1.cpp
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
    if ( root1 == NULL && root2 == NULL ) {
        return true;
    }
    if ( root1 == NULL || root2 == NULL )  {
        return false;
    }
    return  root1->data == root2->data && checkMirror(root1->left, root2->right) && checkMirror(root1->right, root2->left);
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}

