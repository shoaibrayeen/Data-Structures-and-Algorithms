//
//  q5.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 05/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool check( vector <string> text ,vector<string> pattern){
    long text_size = text.size();                           // size of text vector
    long pattern_size = pattern.size();                     // size of pattern vector
    if( text_size  < pattern_size ) {
        // if size of pattern is greater than size of text , then it's not possible to search pattern in text. so return false
        return false;
    }
    int itr1 = 0;                                           // for text pointer
    int itr2 = 0;                                           // for pattern pointer
    while(itr1 < text_size && itr2 < pattern_size ) {
        if( text[itr1].compare(pattern[itr2]) == 0 ) {            // if matched , then increment both pointer
            itr1++;
            itr2++;
        }
        else {
            itr1++;                                         // otherwise increment text pointer only
        }
    }
    if ( itr2 == pattern_size ) {
        // if pattern pointer is equal to size of pattern , then pattern exists in the text
        return true;
    }
    else {
        // otherwise text does not contain pattern
        return false;
    }
}


int main() {
    vector <string> text;
    vector <string> pattern;
    cout << "\nEnter Text\n";
    string temp ="";
    while(true) {
        getline(cin , temp);
        if (temp == "-1" ) {
            break;
        }
        text.push_back(temp);
    }
    temp = " ";
    cout << "\nEnter Pattern\n";
    while(true) {
        getline(cin ,temp);
        if (temp == "-1" ) {
            break;
        }
        pattern.push_back(temp);
    }
    if( check( text , pattern ) ) {
        cout<<"\nText contains Pattern\n";
    }
    else {
        cout<<"\nText does not contain Pattern\n";
    }
    return 0;
}


/*
input type -> enter an event and press enter
exit -> for exiting enter -1 in new line and press enter
*/
