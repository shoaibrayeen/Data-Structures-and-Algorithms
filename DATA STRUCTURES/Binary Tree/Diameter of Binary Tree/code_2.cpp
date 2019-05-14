//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
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
    int diameter(bnode*);
    int height(bnode* , int&);
};
btree::btree() {
    
    root = NULL;
}
bnode* btree:: newNode(int value) {
    
    bnode* temp = new bnode;
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
}


void btree::display() {
    insert();
    cout << "\nDiameter of Tree\t:\t" << diameter(root);
    cout << endl;
}

int btree::diameter(bnode* root) {
    if (root == NULL)
        return 0;
    int ans = INT_MIN;
    height(root, ans);
    return ans;
}

int btree::height(bnode* root , int & ans) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);
    ans = max(ans, 1 + left_height + right_height);
    return 1 + max(left_height, right_height);
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
