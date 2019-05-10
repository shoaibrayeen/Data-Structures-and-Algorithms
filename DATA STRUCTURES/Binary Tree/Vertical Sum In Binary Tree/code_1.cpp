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
    void verticalSumUtil(bnode *, int, map<int, int> &);
    void maxSum(bnode*);
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
}


void btree::display() {
    insert();
    cout << "\n---------------------------------------";
    cout << "\nHorizontal Distance\t|\tVertical Sum\n";
    cout << "---------------------------------------\n";
    maxSum(root);
    cout << "---------------------------------------\n";
    cout << endl;
}

void btree::verticalSumUtil(bnode *node, int hd, map<int, int> &Map) {
    if (node == NULL) {
        return;
    }
    verticalSumUtil(node->left, hd - 1, Map);
    Map[hd] += node->data;
    verticalSumUtil(node->right, hd + 1, Map);
    
}

void btree::maxSum(bnode* root) {
    map < int, int> Map;
    map < int, int> :: iterator it;
    verticalSumUtil(root, 0, Map);
    for (it = Map.begin(); it != Map.end(); ++it) {
        cout << "\t\t" <<it->first << "\t\t\t|\t\t" << it->second << endl;
    }
}


int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
