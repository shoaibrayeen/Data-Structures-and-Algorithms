//
//  code_1.cpp
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
    int sumOfLeafNodesAtMinLevel(bnode*);
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
    root->left->right->left = newNode(8);
    root->right->left->right = newNode(9);
}


void btree::display() {
    
    insert();
    cout << "\nSum of Leaf Nodes At Minimum Level\t:\t" << sumOfLeafNodesAtMinLevel(root) << endl;
}

int btree::sumOfLeafNodesAtMinLevel(bnode* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->data;
    }
    queue<bnode*> q;
    int sum = 0;
    bool f = true;
    q.push(root);
    while (f) {
        int nc = int(q.size());
        while (nc--) {
            bnode* top = q.front();
            q.pop();
            if (!top->left && !top->right) {
                sum += top->data;
                f = false;
            }
            else {
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
        }
    }
    return sum;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
