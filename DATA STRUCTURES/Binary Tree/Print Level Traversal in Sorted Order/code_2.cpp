//
//  code_2.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <queue>
#include <vector>
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
    void sortedLevelOrder(bnode*);
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
    root->right->left = newNode(8);
    root->right->right = newNode(1);
}
void btree::display() {
    insert();
    cout << "\nSorted Order\n";
    sortedLevelOrder(root);
}

void btree::sortedLevelOrder(bnode* root) {
    if (root == NULL) {
        return;
    }
    queue<bnode*> q;
    priority_queue<int, vector<int>, greater<int> > current_level;
    priority_queue<int, vector<int>, greater<int> > next_level;
    q.push(root);
    q.push(NULL);
    current_level.push(root->data);
    while (q.empty() == false) {
        int data = current_level.top();
        bnode* node = q.front();
        if (node == NULL) {
            q.pop();
            if (q.empty()) {
                break;
            }
            q.push(NULL);
            cout << "\n";
            current_level.swap(next_level);
            continue;
        }
        cout << data << "\t";
        
        q.pop();
        current_level.pop();
        if (node->left != NULL) {
            q.push(node->left);
            next_level.push(node->left->data);
        }
        if (node->right != NULL) {
            q.push(node->right);
            next_level.push(node->right->data);
        }
    }
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
