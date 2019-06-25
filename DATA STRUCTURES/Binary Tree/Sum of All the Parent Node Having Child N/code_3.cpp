//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
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
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    int sumOfParentOfX(bnode*  , int);
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
    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(7);
    root->left->right = newNode(2);
    root->right->left = newNode(2);
    root->right->right = newNode(3);
}


void btree::display() {
    
    insert();
    int n;
    cout << "\nEnter Node\t:\t";
    cin >> n;
    cout << "\nSum of Nodes\t:\t" << sumOfParentOfX(root, n);
}

int btree::sumOfParentOfX(bnode* root, int x) {
    int sum = 0;
    if (!root) {
        return 0;
    }
    stack <bnode*> s;
    s.push(root);
    while(!s.empty()) {
        root = s.top();
        s.pop();
        if ((root->left && root->left->data == x) || (root->right && root->right->data == x)) {
            sum += root->data;
        }
        if(root->left) {
            s.push(root->left);
        }
        if(root->right) {
            s.push(root->right);
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
