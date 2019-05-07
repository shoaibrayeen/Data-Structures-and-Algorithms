//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <queue>
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
    void verticalView(bnode*);
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
    root->right->right->right = newNode(9);
    root->right->right->left= newNode(10);
    root->right->right->left->right= newNode(11);
    root->right->right->left->right->right= newNode(12);
}


void btree::display() {
    insert();
    cout << "\nVertical Order\n";
    verticalView(root);
    cout << endl;
}

void btree::verticalView(bnode* root) {
    if (!root) {
        return;
    }
    map < int,vector<int> > m;
    int hd = 0;
    queue<pair<bnode*, int> > que;
    que.push(make_pair(root, hd));
    
    while (!que.empty()) {
        pair<bnode *,int> temp = que.front();
        que.pop();
        hd = temp.second;
        bnode* node = temp.first;
        m[hd].push_back(node->data);
        
        if (node->left != NULL) {
            que.push(make_pair(node->left, hd-1));
        }
        if (node->right != NULL) {
            que.push(make_pair(node->right, hd+1));
        }
    }
    map< int,vector<int> > :: iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i) {
            cout << it->second[i] << "\t";
        }
        cout << endl;
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
