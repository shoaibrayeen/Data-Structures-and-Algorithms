//
//  code_5.cpp
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
    void rightView(bnode*);
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
    root->right->left->right = newNode(8);
}


void btree::display() {
    insert();
    cout << "\nRight View\t:\t";
    rightView(root);
    cout << endl;
}

void btree::rightView(bnode* root) {
    if (!root) {
        return;
    }
    queue<bnode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = int(q.size());
        for(int i = 1; i <= n; i++) {
            bnode* temp = q.front();
            q.pop();
            if (i == n) {
                cout << temp->data << "\t";
            }
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
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
