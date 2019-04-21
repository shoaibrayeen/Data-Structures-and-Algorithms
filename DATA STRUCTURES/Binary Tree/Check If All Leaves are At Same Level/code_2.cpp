//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <queue>
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
    bool isSameLevel(bnode*);
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
    root               = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
}


void btree::display() {
    
    insert();
    if(isSameLevel(root)) {
        cout << "\nAll Leaves are at same level.\n";
        return;
    }
    cout << "\nAll leaver are at different level\n";
}

bool btree::isSameLevel(bnode *root) {
    
    if (!root) {
        return true;
    }
    queue<bnode*> q;
    q.push(root);
    
    int result = INT_MAX;
    int level = 0;
    while (!q.empty()) {
        int size = int(q.size());
        level += 1;
        while(size > 0){
            bnode* temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                if(!temp->left->right && !temp->left->left) {
                    if (result == INT_MAX) {
                        result = level;
                    }
                    else if (result != level) {
                        return false;
                    }
                }
            }
            if (temp->right) {
                q.push(temp->right);
                if (!temp->right->left && !temp->right->right) {
                    if (result == INT_MAX) {
                        result = level;
                    }
                    else if(result != level) {
                        return false;
                    }
                }
                
            }
            size -= 1;
        }
    }
    
    return true;
}

int main() {
    btree obj;
    obj.display();
    cout << "\n";
    return 0;
}
