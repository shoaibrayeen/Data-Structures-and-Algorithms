//
//  code_1.cpp
//  Problems
//
//  Created by Mohd Shoaib Rayeen on 22/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class SNode {
    /*
     objective: class for a Node for Single Linked list
     input parameters: none
     output value: none
     description: SNode class defines the node structure
     approach: Class defines data item is names element with datatype string
     and link is named next of snode type
     */
    private:
    string elem;
    SNode* next;
    friend class SLinkedList; // provides SLinkedList access to SNode
};


class SLinkedList {
    /*
     objective: Single LInked List class
     input parameters: none
     output value: none
     side effects: Class SlinkedList defines Single Linked LIst class
     approach: Class definition
     */
    public:
        SLinkedList();                            // empty list constructor
        ~SLinkedList();                            // destructor
        bool empty() const;                     // is list empty?
        const string& front() const;             // get front element
        void addFront(const string& e);         // add to front of list
        void addBack(const string& e);             // add to back of list
        void removeFront();                         // remove from front
        void removeEnd();                        // remove from end
        void print();                             // prints the SLL
        void mainloop();
    private:
        SNode* head;                             // pointer to the head of list
};

SLinkedList::SLinkedList() {
    /*
     objective: constructor of class
     input parameters: none
     output value: none
     approach: initializing head as NULL
     */
    head = NULL;
}

SLinkedList:: ~SLinkedList() {
    /*
     objective: destructor of class
     input parameters: none
     output value: none
     approach: deleting each element of class
     */
    if( head == NULL ) {
        return;
    }
    while ( head->next != NULL ) {
        SNode * temp = head;
        head  = head->next;
        delete temp;
    }
    delete head;
}

bool SLinkedList:: empty() const {
    /*
     objective: empty()
     input parameters: none
     output value: none
     approach: checking List is empty or not by comparing with head
     */
    if ( head == NULL ) {
        return true;
    }
    return false;
}

const string& SLinkedList::front() const {
    /*
     objective: accessing front element of linked list
     input parameters: none
     output value: data of head
     approach: returning data of head
     */
    return head->elem;
}

void SLinkedList::addFront(const string & e){
    /*
     objective: adding element from front
     input parameters: new value which has to inserted
     output value: none
     approach: updating head after adding node
     */
    SNode* newNode = new SNode;
    newNode->next = NULL;
    newNode->elem = e;
    if( empty()) {
        head = newNode;
        print();
        return;
    }
    newNode->next = head;
    head = newNode;
    print();
}

void SLinkedList::addBack(const string &e ) {
    /*
     objective: adding element at the back of list
     input parameters: new value which has to inserted
     output value: none
     approach: Linked new node at the end ( using iteration )
     */
    SNode* newNode = new SNode;
    newNode->next = NULL;
    newNode->elem = e;
    if(empty()) {
        head = newNode;
        print();
        return;
    }
    SNode* temp = head;
    while(temp->next != NULL ) {
        temp = temp->next;
    }
    temp->next = newNode;
    print();
}

void SLinkedList::removeFront() {
    /*
     objective: removing element from front
     input parameters: none
     output value: none
     approach: updating head after deletion
     */
    if( empty() ) {
        cout << "\nList is Empty.\n";
        return;
    }
    SNode* temp = head;
    head  = head->next;
    cout << "\nDeleted Element\t:\t" << temp->elem;
    delete temp;
    print();
}

void SLinkedList::removeEnd() {
    /*
     objective: deleting at the end
     input parameters: none
     output value: none
     approach: using iteration
     */
    if( empty() ) {
        cout << "\nList is Empty.\n";
        return;
    }
    SNode* temp = head;
    if(head->next == NULL ) {
        removeFront();
        return;
    }
    while(temp->next->next != NULL ) {
        temp = temp->next;
    }
    SNode* p = temp->next;
    temp->next = NULL;
    cout << "\nDeleted Element\t:\t" << p->elem;
    delete p;
    print();
}
void SLinkedList::print() {
    /*
     objective: printing Linked List
     input parameters: none
     output value: none
     approach: using iteration
     */
    if(empty()) {
        cout << "\nList is Empty.\n";
        return;
    }
    SNode* temp = head;
    cout << "\nList\n";
    while(temp->next != NULL ) {
        cout << temp->elem << "\n";
        temp = temp->next;
    }
    cout << temp->elem << "\n";
}

void SLinkedList::mainloop() {
    /*
     objective: used for less interaction with main
     input parameters: none
     output value: none
     approach: accessing each functions in switch case
     */
    string str;
    char choice;
    bool done = true;
    while ( done ) {
        cout << "\n\t\tSingle Linked List Menu";
        cout << "\n1. Insertion at the beginning";
        cout << "\n2. Insertion at the end";
        cout << "\n3. Deletion from the beginning";
        cout << "\n4. Deletion from the end";
        cout << "\n5. Front data of the list";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice;
        switch (choice) {
            case '1':   cout << "\nEnter String\t:\t";
                        cin >> str;
                        addFront(str);
                        break;
            case '2':   cout << "\nEnter String\t:\t";
                        cin >> str;
                        addBack(str);
                        break;
            case '3':   removeFront();
                        break;
            case '4':   removeEnd();
                        break;
            case '5':   if(!empty()) {
                cout << "\nFront of List\t:\t" << front();
                            break;
                        }
                        cout << "\nList is Empty\n";
                        break;
            case '6':   done = false;
                        break;
            default:    cout << "\nWrong Input\n";
                        break;
        }
    }
}
int main() {
    SLinkedList obj;
    obj.mainloop();
    return 0;
}
