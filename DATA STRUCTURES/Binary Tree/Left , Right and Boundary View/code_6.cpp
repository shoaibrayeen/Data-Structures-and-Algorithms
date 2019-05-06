//
//  code_6.cpp
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
    void boundaryView(bnode*);
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
    root = newNode(20);
    
    root->left = newNode(8);
    root->right = newNode(22);
    
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    
    root->right->right = newNode(25);
}


void btree::display() {
    insert();
    cout << "\nBoundary View\t:\t";
    boundaryView(root);
    cout << endl;
}

void btree::boundaryView(bnode* root) {
    if (root) {
        if (!(root->left) && !(root->right)) {
            cout << root->data << endl;
            return;
        }
        vector<bnode*> list;
        list.push_back(root);
        bnode* L = root->left;
        while (L->left) {
            list.push_back(L);
            L = L->left;
        }
        queue<bnode*> q;
        q.push(root);
        while (!q.empty()) {
            bnode* temp = q.front();
            q.pop();
            if (!(temp->left) && !(temp->right)) {
                list.push_back(temp);
            }
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        vector<bnode*> list_r;
        bnode* R = root->right;
        while (R->right) {
            list_r.push_back(R);
            R = R->right;
        }
        reverse(list_r.begin(), list_r.end());
        list.insert(list.end(), list_r.begin(), list_r.end());
        for (auto i : list) {
            cout << i->data << "\t";
        }
        cout << endl;
        return;
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
