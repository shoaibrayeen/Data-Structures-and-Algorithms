//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <map>
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
    void preorder(bnode*);
    void postorder(bnode*);
    void inorder(bnode*);
    void printDiagonal(bnode*);
    void diagonalPrintUtil(bnode* root, int d, map<int, vector<int>> &diagonalPrint);
    //void diagonalPrintUtil(bnode* , int , map<int , vector<int>>);
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
    /*
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9); */
    /*
    root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
     */
}
void btree::display() {
    
    insert();
    cout << "\nInorder\t\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t\t:\t";
    postorder(root);
    cout << "\nPreorder\t\t:\t";
    preorder(root);
    cout << "\nDiagonal Traversal\n";
    printDiagonal(root);
}
void btree :: postorder(bnode* root) {
    
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void btree :: preorder(bnode* root) {
    
    if (root == NULL) {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void btree :: inorder(bnode* root) {
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}



void btree::diagonalPrintUtil(bnode* root, int d, map<int, vector<int>> &diagonalPrint) {
    if (!root) {
        return;
    }
    diagonalPrint[d].push_back(root->data);
    diagonalPrintUtil(root->left, d + 1, diagonalPrint);
    diagonalPrintUtil(root->right, d, diagonalPrint);
}

void btree::printDiagonal(bnode* root) {
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
    for (auto it = diagonalPrint.begin(); it != diagonalPrint.end(); ++it) {
        for (auto itr = it->second.begin(); itr != it->second.end(); ++itr) {
            cout << *itr  << "\t";
        }
        cout << "\n";
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
