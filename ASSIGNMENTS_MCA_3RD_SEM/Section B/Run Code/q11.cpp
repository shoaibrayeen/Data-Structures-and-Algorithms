//
//  q11.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 14/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

class saveDelhiCity {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : creating a class to count number of ways to save Delhi
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :
     class defines some member functions which can be accessed publicly :-
     insert() which takes input for N and K
     mainFunction() which computes number of ways
     helper() which calls member functions.
     
     ------------------------------------------------------------------------------------------------
     */
    public:
    int n , k;
    int mainFuntion(int n , int k);
    void insert();
    void helper();
};

void saveDelhiCity::insert() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : taking input
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :
     using console
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nEnter k\t:\t";
    cin >> k;
}

int saveDelhiCity::mainFuntion(int n , int k) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : counting number of ways
     
     ------------------------------------------------------------------------------------------------
     input parameter : n -> total number of people
                       k -> atleast people must be in a group
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : using recursion
                   * start from  n , k
                   * if n < k , then call n - k , k and n , k + 1
                   * and count every call which satisfies constraints.
     ------------------------------------------------------------------------------------------------
     */
    if( n < k && n > 0 ) {
        return 0;
    }
    else if( n == 0 ) {
        return 1;
    }
    else {
        return mainFuntion( n - k , k) + mainFuntion( n , k + 1);
    }
}

void saveDelhiCity::helper() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling member function
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : calling member function
     
     ------------------------------------------------------------------------------------------------
     */
    insert();
    cout << "\nNumber of Ways\t:\t" << mainFuntion( n, k);
}
/*
int main() {
    saveDelhiCity obj;
    obj.helper();
    cout << endl;
    return 0;
}
*/
