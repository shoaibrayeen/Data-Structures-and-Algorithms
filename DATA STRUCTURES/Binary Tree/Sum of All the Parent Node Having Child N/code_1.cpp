//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
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
    int sumOfParentOfXUtil(bnode* , int );
    void sumOfParentOfX(bnode* , int & , int);
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
    cout << "\nSum of Nodes\t:\t" << sumOfParentOfXUtil(root, n);
}

void btree::sumOfParentOfX(bnode* root, int& sum, int x) {
    if (!root) {
        return;
    }
    if ((root->left && root->left->data == x) || (root->right && root->right->data == x)) {
        sum += root->data;
    }
    sumOfParentOfX(root->left, sum, x);
    sumOfParentOfX(root->right, sum, x);
    
}

int btree::sumOfParentOfXUtil(bnode* root, int x) {
    int sum = 0;
    sumOfParentOfX(root, sum, x);
    return sum;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
