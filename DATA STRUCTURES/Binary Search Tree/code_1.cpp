//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 10/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<stdlib.h>
using namespace std;


struct node {
    int key;
    node *left, *right;
};

node *newNode(int item) {
    node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout <<  root->key << "\t";
        inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != NULL) {
        cout <<  root->key << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout <<  root->key << "\t";
    }
}


node* insert(node* node, int key) {
    if (node == NULL) {
      return newNode(key);
    }
    if (key <= node->key) {
        node->left  = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    } 
    return node;
}

node * minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

node* deleteNode(struct node* root, int key) { 
    if (root == NULL) {
      return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->key == key) {
            root = NULL;
            free(root);
            return root;
        }
        else if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

bool Search(node *root, int key) {
    while (root != NULL) {
        if (key > root->key) {
            root = root->right;
        }
        else if (key < root->key) {
            root = root->left;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    node *root = NULL;
    int value;
    char choice;
    bool done = true;
    while(done) {
        cout << "\n\n\t\t--------Binary Search Tree-------";
        cout << "\n 1. Insertion";
        cout << "\n 2. Displaying Tree";
        cout << "\n 3. Delete a node";
        cout << "\n 4. Search in the Tree";
        cout << "\n 5. Exit ";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case '1'  : cout << "\n Enter the element\t:\t";
                        cin >> value;
                        if(root == NULL ) {
                            root = insert(root, value);
                        }
                        else {
                            insert(root , value);
                        }
                    break;
            case '2'  :
                        if(root == NULL ) {
                            cout << "\n Tree is Empty\n";
                            break;
                        }
                        cout << "\n Inorder\t:\t";
                        inorder(root);
                        cout << "\n Preorder\t:\t";
                        preorder(root);
                        cout << "\n Postorder\t:\t";
                        postorder(root);
                        break;
            case '3'  :
                        if(root == NULL ) {
                            cout << "\n Tree is Empty\n";
                            break;
                        }
                        cout << "\n Enter the element\t:\t";
                        cin >> value;
                        if(!Search(root , value)) {
                            cout << "\n" << value << " is not in the Tree\n";
                            break;
                        }
                        root = deleteNode(root , value);
                        break;
            case '4'  :
                        if(root == NULL ) {
                            cout << "\n Tree is Empty\n";
                            break;
                        }
                        cout << "\n Enter the element\t:\t";
                        cin >> value;
                        if(!Search(root , value)) {
                            cout << "\n" << value << " is not available in the Tree\n";
                        }
                        else {
                            cout << "\n" << value << " is available in the Tree\n";
                        }
                        break;
            case '5'  : done = false;
                         break;
            default :   cout << "\n Invalid Choice\n ";
        }
    }
    return 0;
}
