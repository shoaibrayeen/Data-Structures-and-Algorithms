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
    bnode *root, *root1;
    btree();
    void insert();
    void display();
    void inorder(bnode*);
    bnode* newNode(int);
    bnode* Merge(bnode* , bnode*);
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
    
    root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->right = newNode(6);
}

void btree::display() {
    insert();
    bnode* res =  Merge(root, root1);
    cout << "\nInorder of Merge Tree\t:\t";
    inorder(res);
    
}

void btree::inorder(bnode * root) {
    if (root) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

struct snode {
    bnode *l, *r;
};

bnode *btree::Merge(bnode * t1, bnode * t2) {
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    stack<snode> s;
    snode temp;
    temp.l = t1;
    temp.r = t2;
    s.push(temp);
    snode n;
    while (! s.empty()) {
        n = s.top();
        s.pop();
        if (n.l == NULL|| n.r == NULL) {
            continue;
        }
        n.l->data += n.r->data;
        if (n.l->left == NULL) {
            n.l->left = n.r->left;
        }
        else {
            snode t;
            t.l = n.l->left;
            t.r = n.r->left;
            s.push(t);
        }
        if (n.l->right == NULL) {
            n.l->right = n.r->right;
        }
        else {
            snode t;
            t.l = n.l->right;
            t.r = n.r->right;
            s.push(t);
        }
    }
    return t1;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
