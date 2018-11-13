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

bool check( vector <string> text ,vector<string> pattern) {
     /*
     ------------------------------------------------------------------------------------------------
     
     objective : checking text contains pattern or not
     
     ------------------------------------------------------------------------------------------------
     input parameter : text -> File/String Containing Long Sequences
                       pattern -> File/String Containing SubSequences
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : True -> if text contains pattern
                        False -> if text does not contain pattern
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   Calculating size of both string. If text_size is less than pattern_size , then 
                     It's not possible to search pattern in text.
                     Otherwise -> Within a while loop [ Loop ends if either text ends or pattern ends ]
                                  two pointers [ 1st -> text , 2nd -> pattern ]
                                  check if element at one index is matched , then increase both pointers
                                  otherwise just increase 1st Pointer.
                                  
                                  After ending to loop , if 2nd pointer is equal to text , then text contains pattern
                                  otherwise text does not contain pattern.
                        
     
     ------------------------------------------------------------------------------------------------
     */
    
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
     /*
     ------------------------------------------------------------------------------------------------
     
     objective : main of the program
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    :   Taking input from user and Calling check function
                     Note -> 
                        For Text and Pattern :
                        Enter one Event and press enter 
                        If want to end the string -> enter -1 and press enter
     
     ------------------------------------------------------------------------------------------------
     */
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


