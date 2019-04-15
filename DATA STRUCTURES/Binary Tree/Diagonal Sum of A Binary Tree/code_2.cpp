//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
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
    void printDiagonal(bnode*);
    void diagonalPrintUtil(bnode* root, int d, map<int, vector<int>> &diagonalPrint);
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
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);
}
void btree::display() {
    
    insert();
    cout << "\nDiagonal Traversal\n";
    printDiagonal(root);
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
        int sum = 0;
        for (auto itr = it->second.begin(); itr != it->second.end(); ++itr) {
            sum += *itr;
            cout << *itr  << "\t";
        }
        cout << "\nSum\t:\t" << sum << endl;
        sum = 0;
        cout << "\n";
    }
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
