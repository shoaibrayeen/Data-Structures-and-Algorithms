//
//  q6.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 12/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
using namespace std;

class equivalence_tester {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating a class for checking that n/2 cards out of n are equivalent or not.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :
                    Here's data structure is either multiset or multimap
                    class defines some member functions which can be accessed publicly :-
                    insert_multimap() which takes input to insert in multimap
                    check_multimap() which checks cards are equivalent tester or not.
                    insert_multiset() which takes input to insert in multimap
                    check_multiset() which checks cards are equivalent tester or not.
                    helper() which calls member functions.
     
     ------------------------------------------------------------------------------------------------
     */
    
    public:
        multimap <int, int> map;
        multiset <int> mset;
        int n;
        void insert_multimap();
        void insert_multiset();
        bool check_multimap();
        bool check_multiset();
        void helper();
};

void equivalence_tester::insert_multimap() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insertion into multimap and displaying entered data
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : inserting using pair and displaying using iterator
     
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\nEnter Number of Card\t:\t";
    cin >> n;
    int temp1 , temp2;
    for ( int i = 0; i < n; i++) {
        cout << "\nEnter Account Number\t:\t";
        cin >> temp1;
        cout << "\nEnter Card Number\t\t:\t";
        cin >> temp2;
        map.insert(pair <int , int>(temp1, temp2));
    }
    multimap <int, int> :: iterator itr;
    cout << "\nAccount Number\t|\tCard Number\n";
    for (itr = map.begin(); itr != map.end(); ++itr ) {
        cout << "\t" << itr->first << "\t\t\t|\t" << itr->second << "\n";
    }
}

void equivalence_tester::insert_multiset() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insertion into multiset and displaying entered data
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : inserting using temporary variable and displaying using iterator
     
     
     ------------------------------------------------------------------------------------------------
     */
    
    cout << "\nEnter Number of Card\t:\t";
    cin >> n;
    int temp1;
    cout << "\nEnter Card Numbers\n";
    for ( int i = 0; i < n; i++) {
        cin >> temp1;
        mset.insert(temp1);
    }
    multiset <int> :: iterator itr;
    cout << "\nEntered Details\t:\t";
    for (itr = mset.begin(); itr != mset.end(); ++itr) {
        cout << *itr << "\t";
    }
    cout << endl;
}

bool equivalence_tester::check_multimap() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : to check that n/2 cards out of n are equivalent or not.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : True if n/2 equivalent cards exists
                        False otherwise
     
     ------------------------------------------------------------------------------------------------
     
     approach    :  iterating using given details
                    If size of any key is greater than n/2  , then return True
                    Otherwise False
     
     
     ------------------------------------------------------------------------------------------------
     */
    
    multimap <int, int> :: iterator itr;
    for (itr = map.begin(); itr != map.end(); ++itr ) {
        if ( map.count(itr->first) > map.size()/2 ) {
            return true;
        }
    }
    return false;
}
bool equivalence_tester::check_multiset() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : that n/2 cards out of n are equivalent or not.
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : True if n/2 equivalent cards exists
                        False otherwise
     
     ------------------------------------------------------------------------------------------------
     
     approach    : iterating using given details
                   If size of any element is greater than n/2  , then return True
                   Otherwise False
     
     
     ------------------------------------------------------------------------------------------------
     */
    
    multiset <int> :: iterator itr;
    for (itr = mset.begin(); itr != mset.end(); ++itr ) {
        if ( mset.count(*itr) > mset.size()/2 ) {
            return true;
        }
    }
    return false;
}
void equivalence_tester::helper() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling member function
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : using loop and swicth , calling member functions
     
     
     ------------------------------------------------------------------------------------------------
     */
    bool done = true;
    while(done) {
        cout << "\n\n----------EQUIVALENCE TESTER MENU-----------\n";
        cout << "\n1.Using Multiset\n2.Using Multimap\n3.Go to Main Menu\n4.Exit\n";
        char choice;
        cout << "\nEnter Your Choice\t:\t";
        cin >> choice ;
        switch(choice) {
            case '1' :  insert_multiset();
                        if(check_multiset()) {
                            cout << "\nThere exists a set of more than n/2 cards that are all equivalent to one another.\n";
                        }
                        else {
                            cout << "\nThere does not exist any set of more than n/2 cards that are all equivalent to one another.\n";
                        }
                        mset.clear();
                        break;
            case '2' :  insert_multimap();
                        if(check_multimap()) {
                            cout << "\nThere exists a set of more than n/2 cards that are all equivalent to one another.\n";
                        }
                        else {
                            cout << "\nThere does not exist any set of more than n/2 cards that are all equivalent to one another.\n";
                        }
                        map.clear();
                        break;
            case '3' :  done = false;
                        break;
            case '4' :  exit(0);
            default:    cout << "\nInvalid Input\n";
        }
    }
}
int main() {
    equivalence_tester obj;
    obj.helper();
    return 0;
}
