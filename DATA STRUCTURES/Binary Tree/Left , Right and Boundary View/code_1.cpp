//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
using namespace std;

struct bnode {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure for binary tree
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  structure defines a node structure which contains data ( int type ) and
     left and right ( bnode types for storing address of left and right elements )
     
     ------------------------------------------------------------------------------------------------
     */
    int data;
    bnode *left;
    bnode *right;
};

class btree {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : binary tree class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
     1. btree() for initializing the pointer
     2. insert() for insertion in binary tree
     3. display() for displaying binary tree
     6. newNode() for creating new node
     7. preorder() for displaying preorder of tree
     8. postorder() for displaying postorder of tree
     9. inorder() for displaying inorder of tree
     10. creating root node for binary tree
     11. arr[] for storing path and pathlen for storing length of path for every leaf node
     ------------------------------------------------------------------------------------------------
     */
public:
    bnode *root;
    btree();
    void insert();
    void display();
    bnode* newNode(int);
    void preorder(bnode*);
    void postorder(bnode*);
    void inorder(bnode*);
    void printLeaves(bnode*);
    void boundaryView(bnode*);
    void leftView(bnode*);
    void rightView(bnode*);
};
btree::btree() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing root as NULL and pathlen as zero
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to root and 0 to pathlen
     
     ------------------------------------------------------------------------------------------------
     */
    root = NULL;
}
bnode* btree:: newNode(int value) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating newnode and assigning it to given value
     
     ------------------------------------------------------------------------------------------------
     input parameter : value which has to inserted into binary tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : new node which is created
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   creating a bnode type node and assiging its left and right as NULL and data as value
     
     ------------------------------------------------------------------------------------------------
     */
    bnode* temp=new bnode;
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void btree:: insert() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insertion in binary tree
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   inserting nodes from root , then its right & left and so on
     
     ------------------------------------------------------------------------------------------------
     */
    /*
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    root->left->right->left = newNode(9);
    */
    root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
}
void btree::display() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying binary tree and path
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling insert() , inorder() , preorder() , postorder and path() functions
     
     ------------------------------------------------------------------------------------------------
     */
    insert();
    cout << "\nInorder\t\t\t:\t";
    inorder(root);
    cout << "\nPostorder\t\t:\t";
    postorder(root);
    cout << "\nPreorder\t\t:\t";
    preorder(root);
    cout << "\nBoundary View\t:\t";
    boundaryView(root);
    cout << "\nLeft View\t\t:\t";
    leftView(root);
    cout << "\nRight View\t\t:\t";
    rightView(root);
    
}
void btree :: postorder(bnode* root) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in postorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
     - left , right and then value of pointer
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}

void btree :: preorder(bnode* root) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in preorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
     - value of pointer , left and right
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL) {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void btree :: inorder(bnode* root) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying tree in inorder recursively
     
     ------------------------------------------------------------------------------------------------
     input parameter : root of tree
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   calling this function recursively in following sequence :-
     - left , value of pointer and right
     
     ------------------------------------------------------------------------------------------------
     */
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    cout << root->data << "\t";
    preorder(root->right);
}


void btree::leftView(bnode* root)
{
    if (root) {
        if (root->left) {
            // to ensure top down order, print the node
            // before calling itself for left subtree
            cout << root->data << "\t";
            leftView(root->left);
        }
        else if (root->right) {
            cout << root->data << "\t";
            leftView(root->right);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void btree::rightView(bnode* root)
{
    if (root) {
        if (root->right) {
            // to ensure bottom up order, first call for right
            // subtree, then print this node
            rightView(root->right);
            cout << root->data << "\t";
        }
        else if (root->left) {
            rightView(root->left);
            cout << root->data << "\t";
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }
}

// A function to do boundary traversal of a given binary tree
void btree::boundaryView(bnode* root)
{
    if (root) {
        cout << root->data << "\t";
        
        // Print the left boundary in top-down manner.
        leftView(root->left);
        
        // Print all leaf nodes
        printLeaves(root->left);
        printLeaves(root->right);
        
        // Print the right boundary in bottom-up manner
        rightView(root->right);
    }
}
void btree::printLeaves(bnode* root) {
    if (root) {
        printLeaves(root->left);
        if (!(root->left) && !(root->right)) {
            cout << root->data << "\t";
        }
        printLeaves(root->right);
    }
}
int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
