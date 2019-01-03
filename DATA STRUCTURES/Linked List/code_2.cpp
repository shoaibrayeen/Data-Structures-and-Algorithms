 //
//  q3.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include <stack>
using namespace std;
struct slnode {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating structure for singly linked list node
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  structure defines a node structure which contains data ( int type ) and
                    next ( slnode types for storing address of next pointer )
     
     ------------------------------------------------------------------------------------------------
     */
    int data;
    slnode *next;
};

class sll {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : singly linked list class
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   class defines constructor and functions which can be accessed publicly such as :-
                     1. sll() for initializing the pointer
                     2. insert() for inserting variable into linked list
                     3. display() for displaying linked list
                     4. reverse() for reversing linked list in pairs
                     5. mainFunc() for calling member functions
                     6. declaring a pointer named as head
     ------------------------------------------------------------------------------------------------
     */
public:
    slnode *head;
    sll();
    void insert(int);
    void display();
    void reverse();
    void mainFunc();
};
sll::sll() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : initializing head pointer as NULL
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   assigning NULL to head pointer
     
     ------------------------------------------------------------------------------------------------
     */
    head = NULL;
}
void sll::insert(int value) {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : inseting element to linked list
     
     ------------------------------------------------------------------------------------------------
     input parameter : value which has to inserted into linked list
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   This function performs following operations :-
                     1. creating a newnode of slnode type
                     2. if head is NULL , then newnode is assigned as head.
                     3. if head is not NULL , then with the help of another pointer inserting newnode
                        at the end of linked list
                     4. calling display() function after every insertion
     ------------------------------------------------------------------------------------------------
     */
    slnode* newnode=new slnode;
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL) {
        head = newnode;
    }
    else {
        slnode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    cout << "\n List\t:\t";
    display();
}

void sll::display() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying linked list
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this function displays current list with the help of another pointer
     
     ------------------------------------------------------------------------------------------------
     */
    
    if(head==NULL) {
        cout << "\n\n List is Empty....!!!!!!!";
    }
    else {
        slnode *temp = head;
        while(temp->next != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data;
    }
}

void sll:: reverse() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : reversing linked list in pair with the help of external stack
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   This function performs following operations :-
                     1. creating object of external stack
                     2. current pointer is assigned as head and prev is as NULL.
                     3. pushing two element of linked list into external stack
                     4. if prev is NULL , then prev and head is assigned as element at top of stack
                     5. if prev is not NULL , then next of prev is assigned as element at top of stack
                        and prev is updated as next of prev.
                     6. popping element from stack
                     7. repeat step 4 , 5 and 6 till stack is not empty.
                     8. repeating from step 2 to 7 till current is not NULL.
                     9. displaying reverse linked list
     ------------------------------------------------------------------------------------------------
     */
    stack<slnode*> s;
    slnode* current = head;
    slnode* prev = NULL;
    while (current != NULL) {
        s.push(current);
        current = current->next;
        if(current != NULL ) {
            s.push(current);
            current = current->next;
        }
        while (!s.empty()) {
            if (prev == NULL) {
                prev = s.top();
                head = prev;
                s.pop();
            } else {
                prev->next = s.top();
                prev = prev->next;
                s.pop();
            }
        }
    }
    prev->next = NULL;
    display();
}
void sll::mainFunc() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling each function except this function
     
     ------------------------------------------------------------------------------------------------
     input parameter :  none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   this functions performs following operations :-
                     1. inserting in linked list
                     2. reverse of linked list in pair
                     3. exit from program
     
     ------------------------------------------------------------------------------------------------
     */
    int value;
    char choice;
    bool done = true;
    while(done) {
        cout << "\n\n\t\t--------Reverse Linked List Menu-------";
        cout << "\n 1. Insertion";
        cout << "\n 2. Reverse Linked List";
        cout << "\n 3. Go to Main Menu  \n 4. Exit ";
        cout << "\n Enter your Choice\t:\t";
        cin >> choice;
        switch(choice) {
            case '1'  : cout << "\n Enter the element\t:\t";
                        cin >> value;
                        insert(value);
                        break;
            case '2'  : cout << "\n List\t:\t";
                        reverse();
                        break;
            case '3'  : done = false;
                        break;
            case '4'  : exit(0);
            default :   cout << "\n Invalid Choice\n ";
        }
    }
}


int main() {
  sll obj;
  obj.mainFunc();
  return 0;
}
