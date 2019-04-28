//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <stack>
#include <map>
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
    void printTopToBottomPath(bnode* , map<bnode*,bnode*>);
    void printRootToLeaf(bnode*);
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
}


void btree::display() {
    
    insert();
    cout << "\nAll root to Leaf Path\n";
    printRootToLeaf(root);
}

void btree::printTopToBottomPath(bnode* curr, map<bnode*, bnode*> parent) {
    stack<bnode*> stk;
    while (curr) {
        stk.push(curr);
        curr = parent[curr];
    }
    while (!stk.empty()) {
        curr = stk.top();
        stk.pop();
        cout << curr->data << "->";
    }
    cout << endl;
}

void btree::printRootToLeaf(bnode* root) {
    if (root == NULL) {
        return;
    }
    stack<bnode*> nodeStack;
    nodeStack.push(root);
    map<bnode*, bnode*> parent;
    parent[root] = NULL;
    while (!nodeStack.empty()) {
        bnode* current = nodeStack.top();
        nodeStack.pop();
        if (!(current->left) && !(current->right)) {
            printTopToBottomPath(current, parent);
        }
        if (current->right) {
            parent[current->right] = current;
            nodeStack.push(current->right);
        }
        if (current->left) {
            parent[current->left] = current;
            nodeStack.push(current->left);
        }
    }
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
