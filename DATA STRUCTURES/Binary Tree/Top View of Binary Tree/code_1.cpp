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
    int hd;
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
    void topView(bnode*);
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
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
}


void btree::display() {
    insert();
    cout << "\nTop View\t:\t";
    topView(root);
    cout << endl;
}

void btree::topView(bnode* root) {
    if( root == NULL ) {
        return;
    }
    queue<bnode*>q;
    map<int,int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(q.size()) {
        hd = root->hd;
        if( m.count(hd) == 0 ) {
            m[hd] = root->data;
        }
        if(root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if(root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
        
    }
    for( auto i = m.begin(); i != m.end(); i++ ) {
        cout << i->second << "\t";
    }
    
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
