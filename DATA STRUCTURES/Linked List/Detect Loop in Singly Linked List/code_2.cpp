//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
struct Node {
    int data;
    struct Node* next;
};


bool detectLoop(struct Node *head) {
    unordered_set<Node *> temp;
    while (head != NULL) {
        if (temp.find(head) != temp.end()) {
            return true;
        }
        temp.insert(head);
        head = head->next;
    }
    
    return false;
}

struct Node *newNode(int key) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = head->next;
    if( detectLoop(head)) {
        printf("\nLoop Found\n");
    }
    else {
        printf("\nLoop Not Found\n");
    }
    return 0;
}
