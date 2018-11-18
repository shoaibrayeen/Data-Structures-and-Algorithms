//
//  q10.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;


class planningAParty {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating a class to check to whom Alice can invite
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : Here's data structure is multimap.
     class defines some member functions which can be accessed publicly :-
     insert() which takes input from console
     sample1() which is a sample that determines some are invited.
     sample2() which is a sample that determines none are invited.
     check() which checks that everyone satisfies the given conditions or not.
     display() which display details
     mainFunction() which computes number of people can be invited
     remove() which removes a person who does not satisfy given conditions.
     helper() which calls member functions.
     
     ------------------------------------------------------------------------------------------------
     */
    public:
    multimap<char , char> mm;
    int n;
    void insert();
    void remove(char);
    void mainFunction();
    void helper();
    void display();
    bool check();
    void sample1();
    void sample2();
};

void planningAParty::sample1() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : sample input to invite some people
     
     ------------------------------------------------------------------------------------------------
     */
    // Some people are invited
    n = 13;
    // edge with 'a'
    mm.insert(pair<char,char>('a','c'));
    mm.insert(pair<char,char>('a','b'));
    mm.insert(pair<char,char>('a','d'));
    mm.insert(pair<char,char>('a','e'));
    mm.insert(pair<char,char>('a','f'));
    mm.insert(pair<char,char>('a','i'));
    mm.insert(pair<char,char>('a','j'));
    
    // edge with 'b'
    mm.insert(pair<char,char>('b','c'));
    mm.insert(pair<char,char>('b','d'));
    mm.insert(pair<char,char>('b','m'));
    // edge with 'c'
    mm.insert(pair<char,char>('c','g'));
    mm.insert(pair<char,char>('c','b'));
    mm.insert(pair<char,char>('c','d'));
    mm.insert(pair<char,char>('c','e'));
    mm.insert(pair<char,char>('c','f'));
    mm.insert(pair<char,char>('c','i'));
    
    
    //edge with 'd'
    mm.insert(pair<char,char>('d','b'));
    mm.insert(pair<char,char>('d','f'));
    mm.insert(pair<char,char>('d','g'));
    mm.insert(pair<char,char>('d','h'));
    mm.insert(pair<char,char>('d','i'));
    mm.insert(pair<char,char>('d','j'));
    
    //edge with 'e'
    mm.insert(pair<char,char>('e','c'));
    mm.insert(pair<char,char>('e','b'));
    mm.insert(pair<char,char>('e','d'));
    mm.insert(pair<char,char>('e','f'));
    mm.insert(pair<char,char>('e','g'));
    mm.insert(pair<char,char>('e','h'));
    
    
    //edge with 'f'
    mm.insert(pair<char,char>('f','c'));
    mm.insert(pair<char,char>('f','b'));
    mm.insert(pair<char,char>('f','d'));
    mm.insert(pair<char,char>('f','g'));
    mm.insert(pair<char,char>('f','h'));
    mm.insert(pair<char,char>('f','i'));
    
    
    //edge with 'g'
    mm.insert(pair<char,char>('g','a'));
    mm.insert(pair<char,char>('g','b'));
    mm.insert(pair<char,char>('g','l'));
    mm.insert(pair<char,char>('g','e'));
    mm.insert(pair<char,char>('g','f'));
    mm.insert(pair<char,char>('g','i'));
    
    //edge with 'h'
    mm.insert(pair<char,char>('h','a'));
    mm.insert(pair<char,char>('h','b'));
    mm.insert(pair<char,char>('h','k'));
    mm.insert(pair<char,char>('h','c'));
    mm.insert(pair<char,char>('h','d'));
    mm.insert(pair<char,char>('h','e'));
    mm.insert(pair<char,char>('h','m'));
    
    //edge with 'i'
    mm.insert(pair<char,char>('i','c'));
    mm.insert(pair<char,char>('i','b'));
    mm.insert(pair<char,char>('i','d'));
    mm.insert(pair<char,char>('i','e'));
    mm.insert(pair<char,char>('i','f'));
    mm.insert(pair<char,char>('i','g'));
    mm.insert(pair<char,char>('i','m'));
    
    //edge with 'j'
    mm.insert(pair<char,char>('j','a'));
    mm.insert(pair<char,char>('j','b'));
    mm.insert(pair<char,char>('j','h'));
    mm.insert(pair<char,char>('j','l'));
    mm.insert(pair<char,char>('j','c'));
    mm.insert(pair<char,char>('j','d'));
    
    //edge with 'k'
    mm.insert(pair<char,char>('k','a'));
    mm.insert(pair<char,char>('k','c'));
    mm.insert(pair<char,char>('k','e'));
    mm.insert(pair<char,char>('k','f'));
    mm.insert(pair<char,char>('k','g'));
    mm.insert(pair<char,char>('k','m'));
    
    //edge with 'l'
    mm.insert(pair<char,char>('l','a'));
    mm.insert(pair<char,char>('l','d'));
    mm.insert(pair<char,char>('l','c'));
    mm.insert(pair<char,char>('l','f'));
    mm.insert(pair<char,char>('l','g'));
    mm.insert(pair<char,char>('l','m'));
    
    //edge with 'm'
    mm.insert(pair<char,char>('m','g'));
    mm.insert(pair<char,char>('m','e'));
    mm.insert(pair<char,char>('m','a'));
    mm.insert(pair<char,char>('m','b'));
}
void planningAParty::sample2() {
    
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : sample input to invite none
     
     ------------------------------------------------------------------------------------------------
     */
    // No one is invited
    n = 13;
    // edge with 'a'
    mm.insert(pair<char,char>('a','c'));
    mm.insert(pair<char,char>('a','b'));
    mm.insert(pair<char,char>('a','d'));
    mm.insert(pair<char,char>('a','e'));
    mm.insert(pair<char,char>('a','f'));
    mm.insert(pair<char,char>('a','i'));
    mm.insert(pair<char,char>('a','j'));
    mm.insert(pair<char,char>('a','k'));
    mm.insert(pair<char,char>('a','l'));
    
    
    // edge with 'b'
    mm.insert(pair<char,char>('b','c'));
    mm.insert(pair<char,char>('b','d'));
    mm.insert(pair<char,char>('b','m'));
    // edge with 'c'
    mm.insert(pair<char,char>('c','g'));
    mm.insert(pair<char,char>('c','b'));
    mm.insert(pair<char,char>('c','d'));
    mm.insert(pair<char,char>('c','e'));
    mm.insert(pair<char,char>('c','f'));
    mm.insert(pair<char,char>('c','i'));
    
    
    //edge with 'd'
    mm.insert(pair<char,char>('d','b'));
    mm.insert(pair<char,char>('d','f'));
    mm.insert(pair<char,char>('d','g'));
    mm.insert(pair<char,char>('d','h'));
    mm.insert(pair<char,char>('d','i'));
    mm.insert(pair<char,char>('d','j'));
    
    //edge with 'e'
    mm.insert(pair<char,char>('e','c'));
    mm.insert(pair<char,char>('e','b'));
    mm.insert(pair<char,char>('e','d'));
    mm.insert(pair<char,char>('e','f'));
    mm.insert(pair<char,char>('e','g'));
    mm.insert(pair<char,char>('e','h'));
    
    
    //edge with 'f'
    mm.insert(pair<char,char>('f','c'));
    mm.insert(pair<char,char>('f','b'));
    mm.insert(pair<char,char>('f','d'));
    mm.insert(pair<char,char>('f','g'));
    mm.insert(pair<char,char>('f','h'));
    mm.insert(pair<char,char>('f','i'));
    
    
    //edge with 'g'
    mm.insert(pair<char,char>('g','a'));
    mm.insert(pair<char,char>('g','b'));
    mm.insert(pair<char,char>('g','l'));
    mm.insert(pair<char,char>('g','e'));
    mm.insert(pair<char,char>('g','f'));
    mm.insert(pair<char,char>('g','i'));
    
    //edge with 'h'
    mm.insert(pair<char,char>('h','a'));
    mm.insert(pair<char,char>('h','b'));
    mm.insert(pair<char,char>('h','k'));
    mm.insert(pair<char,char>('h','c'));
    mm.insert(pair<char,char>('h','d'));
    mm.insert(pair<char,char>('h','e'));
    mm.insert(pair<char,char>('h','m'));
    
    //edge with 'i'
    mm.insert(pair<char,char>('i','c'));
    mm.insert(pair<char,char>('i','b'));
    mm.insert(pair<char,char>('i','d'));
    mm.insert(pair<char,char>('i','e'));
    mm.insert(pair<char,char>('i','f'));
    mm.insert(pair<char,char>('i','g'));
    mm.insert(pair<char,char>('i','m'));
    
    //edge with 'j'
    mm.insert(pair<char,char>('j','a'));
    mm.insert(pair<char,char>('j','b'));
    mm.insert(pair<char,char>('j','h'));
    mm.insert(pair<char,char>('j','l'));
    mm.insert(pair<char,char>('j','c'));
    mm.insert(pair<char,char>('j','d'));
    
    //edge with 'k'
    mm.insert(pair<char,char>('k','a'));
    mm.insert(pair<char,char>('k','c'));
    mm.insert(pair<char,char>('k','e'));
    mm.insert(pair<char,char>('k','f'));
    mm.insert(pair<char,char>('k','g'));
    mm.insert(pair<char,char>('k','m'));
    
    //edge with 'l'
    mm.insert(pair<char,char>('l','a'));
    mm.insert(pair<char,char>('l','d'));
    mm.insert(pair<char,char>('l','c'));
    mm.insert(pair<char,char>('l','f'));
    mm.insert(pair<char,char>('l','g'));
    mm.insert(pair<char,char>('l','m'));
    
    //edge with 'm'
    mm.insert(pair<char,char>('m','g'));
    mm.insert(pair<char,char>('m','e'));
    mm.insert(pair<char,char>('m','a'));
    mm.insert(pair<char,char>('m','b'));
}


void planningAParty::display() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying details of everyone
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : accessing known people by each person and displaying it
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\n-----------------------------------------------------------------------------";
    cout << "\n|Persont|\tKnown#\t|\t\tKnown People\n";
    cout << "-----------------------------------------------------------------------------\n";
    for(int i = 'a'; i < 'a' + n; i++) {
        if( mm.find(i) != mm.end() ) {
            auto it = mm.equal_range(i);
            cout << "|   " << char(i) << "\t|\t" << mm.count(i) << "\t\t|\t";
            for (auto itr = it.first; itr != it.second; ++itr) {
                cout << itr->second << '\t';
            }
            cout << "\n-----------------------------------------------------------------------------\n";
        }
    }
}

void planningAParty::insert() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insetion by user
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\nEnter Number of People\t:\t";
    cin >> n;
    char dest;
    int tempCount;
    for ( char i = 'a'; i < n + 'a'; i++) {
        cout << "\nEnter Number of Known people by " << char(i) << "\t:\t";
        cin >> tempCount;
        cout << "\nEnter Known People\n";
        for ( int j = 0; j < tempCount; j++) {
            cin >> dest;
            mm.insert(pair<char,char>(char(i),dest));
        }
    }
}



bool planningAParty::check() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : to check that a person satifies given conditions or not
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : true -> if satisfies
                        false -> if does not satisfy
     
     ------------------------------------------------------------------------------------------------
     
     approach    : if degree of the person is less than 5 or greater than n - 5 , then the person does
                   not satisfy the conditions.
     ------------------------------------------------------------------------------------------------
     */
    for ( int i = 'a'; i < 'a' + n; i++ ) {
        if( mm.find(char(i)) != mm.end() ) {
            if( mm.count(i) < 5  || mm.count(i) > n - 5 ) {
                return false;
            }
        }
    }
    return true;
}

void planningAParty::remove(char bad_vertex) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : removing a person who does not satisfy the condtions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  first of all , remove the person from people who knows it and then remove the
                    person
     
     ------------------------------------------------------------------------------------------------
     */
    multimap <char ,char> :: iterator itr , temp;
    for (itr = mm.begin(); itr != mm.end(); ++itr) {
        if(itr->second == bad_vertex) {
            temp = itr;
            mm.erase(temp);
        }
    }
    mm.erase(bad_vertex);
}

void planningAParty::mainFunction() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : to decide who should be invited
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : if does not satisfy then remove.
                   After removing a person , a new person can be turned up who does not satisfy.
                   If all satisfy given condtions , then break.
     
     ------------------------------------------------------------------------------------------------
     */
    while(true) {
        for(int i = 'a'; i < 'a' + n; i++) {
            if( mm.find(char(i)) != mm.end() && (mm.count(i) < 5  || mm.count(i) > n - 5) ) {
                remove(char(i));
            }
        }
        if(check()) {
            break;
        }
    }
}

void planningAParty::helper() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective :  calling member functions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : calling member functions
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\n1.Insertion by User\n2.Sample to Invite Some People\n3.Sample to Invite none\n";
    char choice;
    cout << "\nEnter Your Choice\t:\t";
    cin >> choice ;
    switch(choice) {
       case '1' :  insert();
                        break;
       case '2' :  sample1();
                        break;
       case '3' :  sample2();
                        break;
    }
    display();
    mainFunction();
    if(check() && mm.size() != 0) {
        cout << "\nInvited People\n";
        display();
    }
    else {
        cout << "\nNo one is invited.\n";
    }
    mm.clear();
}
/*
int main() {
    planningAParty obj;
    obj.helper();
    cout << endl;
    return 0;
}
 */
