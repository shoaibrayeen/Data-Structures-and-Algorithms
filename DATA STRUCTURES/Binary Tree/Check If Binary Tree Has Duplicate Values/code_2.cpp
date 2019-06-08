//
 //  code_2.cpp
 //  Algorithm
 //
 //  Created by Mohd Shoaib Rayeen on 15/04/19.
 //  Copyright © 2019 Shoaib Rayeen. All rights reserved.
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
     bool checkDup(bnode*);
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
     root              = newNode(1);
     root->left        = newNode(12);
     root->right       = newNode(8);
     root->left->left  = newNode(3);
     root->left->right = newNode(4);
     root->right->left  = newNode(9);
     root->right->right = newNode(10);
 }
 
 
 void btree::display() {
     insert();
     if(checkDup(root)) {
         cout << "\nTree Contains Duplicated.\n";
         return;
     }
     cout << "\nTree does not contains Duplicated.\n";
 }

 bool btree::checkDup(bnode* root ) {
     if (root == NULL) {
         return true;
     }
     unordered_set<int> s;
     stack <bnode*> s1;
     s1.push(root);
     s.insert(root->data);
     while(!s1.empty()) {
         root = s1.top();
         s1.pop();
         if ( root->left) {
             if (s.find(root->left->data) == s.end()) {
                 s.insert(root->left->data);
                 s1.push(root->left);
             }
             else {
                 return true;
             }
         }
         if ( root->right) {
             if (s.find(root->right->data) == s.end()) {
                 s.insert(root->right->data);
                 s1.push(root->right);
             }
             else {
                 return true;
             }
         }
     }
     return false;
 }
 
 int main() {
     btree obj;
     obj.display();
     cout << "\n";
     return 0;
 }
