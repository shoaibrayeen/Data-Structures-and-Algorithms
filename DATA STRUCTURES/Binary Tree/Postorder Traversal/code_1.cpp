
//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <iostream>
#include <unordered_set>
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
    void postorder(bnode*);
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
    cout << "\nPostorder\t\t\t:\t";
    postorder(root);
}

void btree::postorder(bnode* head) {
    bnode* temp = head;
    unordered_set<bnode*> visited;
    while (temp && visited.find(temp) == visited.end()) {
        if (temp->left && visited.find(temp->left) == visited.end()) {
            temp = temp->left;
        }
        else if (temp->right && visited.find(temp->right) == visited.end()) {
            temp = temp->right;
        }
        else {
            cout << temp->data <<"\t";
            visited.insert(temp);
            temp = head;
        }
    }
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}

