//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node *start) {
    int res = 1;
    struct Node *temp = start;
    while (temp->next != start) {
        res++;
        temp = temp->next;
    }
    return res;
}

int countNodesinLoop(struct Node *list) {
    struct Node  *slow = list, *fast = list;
    
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
            printf("\nLoop Found\n");
            return countNodes(slow);
        }
    }
    printf("\nLoop Not Found\n");
    return 0;
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
    printf("\nNumber of Nodes in Loop\t:\t%d\n", countNodesinLoop(head));
    return 0;
}
