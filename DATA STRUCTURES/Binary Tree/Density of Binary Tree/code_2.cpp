//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
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
    int heighAndSize(bnode* , int &);
    float density(bnode*);
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
    root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
}
void btree::display() {
    
    insert();
    cout << "\nDensity\t\t\t:\t" << density(root);
}



int btree::heighAndSize(bnode* root, int &size) {
    if (root == NULL) {
        return 0;
    }
    queue<bnode *> q;
    q.push(root);
    int height = 0;
    size++;
    while (true) {
        int nodeCount = int(q.size());
        if (nodeCount == 0) {
            return height;
        }
        height++;
        while (nodeCount > 0) {
            bnode *node = q.front();
            q.pop();
            if (node->left != NULL) {
                q.push(node->left);
                size++;
            }
            if (node->right != NULL) {
                q.push(node->right);
                size++;
            }
            nodeCount--;
        }
    }
}

float btree::density(bnode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int size = 0;
    int _height = heighAndSize(root, size);
    
    return (float)size/_height;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
