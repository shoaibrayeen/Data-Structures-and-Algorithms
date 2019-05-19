//
//  code_3.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <stack>
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
    void postorderIterative(bnode*);
    void postorderIterative2(bnode*);
    void postorderMorris(bnode*);
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
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9);
}
void btree::display() {
    insert();
    cout << "\nRecusive Postorder\t\t\t:\t";
    postorder(root);
    cout << "\nIterative Postorder\t\t\t:\t";
    postorderIterative(root);
    cout << "\nIterative Postorder 2\t\t:\t";
    postorderIterative(root);
    cout << "\nUsing Set Postorder\t\t\t:\t";
    postorderMorris(root);
}

void btree :: postorder(bnode* root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void btree:: postorderIterative(bnode* root) {
    if (root == NULL) {
        return;
    }
    stack <bnode*> s;
    do {
        while (root) {
            if (root->right) {
                s.push(root->right);
            }
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (s.empty()) {
            cout << root->data;
            break;
        }
        if ( root->right && s.top() == root->right) {
            s.pop();
            s.push(root);
            root = root->right;
        }
        else {
            cout << root->data << "\t";
            root = NULL;
        }
    } while (!s.empty());
}

void btree:: postorderIterative2(bnode* root) {
    if (root == NULL) {
        return;
    }
    stack <bnode*> s1, s2;
    s1.push(root);
    bnode* node;
    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) {
            s1.push(node->left);
        }
        if (node->right) {
            s1.push(node->right);
        }
    }
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << "\t";
    }
}
void btree::postorderMorris(bnode * root) {
    bnode* temp = root;
    unordered_set<bnode*> visited;
    while (temp && visited.find(temp) == visited.end()) {
        if (temp->left && visited.find(temp->left) == visited.end()) {
            temp = temp->left;
        }
        else if (temp->right && visited.find(temp->right) == visited.end()) {
            temp = temp->right;
        }
        else {
            cout << temp->data << "\t";
            visited.insert(temp);
            temp = root;
        }
    }

}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
