//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <queue>
#include <set>
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
    cout << "\nSorted Order\t:\t";
    sortedLevelOrder(root);
}

void btree::sortedLevelOrder(bnode* root) {
    queue<bnode*> q;
    set<int> s;
    q.push(root);
    q.push(nullptr);
    while (q.empty() == false) {
        bnode* temp = q.front();
        q.pop();
        if (temp == nullptr) {
            if (s.empty() == true) {
                break;
            }
            for (set<int>::iterator it = s.begin();it != s.end(); ++it) {
                cout << *it << "\t";
            }
            q.push(nullptr);
            s.clear();
        }
        else {
            s.insert(temp->data);
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
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
