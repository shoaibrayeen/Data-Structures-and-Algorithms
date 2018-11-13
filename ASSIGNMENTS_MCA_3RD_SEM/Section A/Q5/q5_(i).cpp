//
//  q5.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 05/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

/*
    file should be in text format and separated by delimiter.
    Delimiter : " , "   -> space then comma and then space  that would separate a string
    text_file -> containing sequence
    pattern_file -> containging subsequences from text_file
 
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
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
     
     approach    :   Taking input from file
                     And Calling check function
                     
     
     ------------------------------------------------------------------------------------------------
     */
    // text_file.txt and pattern_file.txt and this program should be in the same file.
    // reading from text_file.txt and storing it in text vector
    vector <string> text;
    vector <string> pattern;
    string temp;
    ifstream myfile1;
    myfile1.open("text_file.txt");
    string line;
    while ( getline (myfile1 , line) ) {
        string temp = "";
        for(int i = 0; i < line.length(); ++i) {
            if( line.substr( i , 3).compare(" , ") != 0) {  // getting ' , ' then store it
                temp += line[i];
            }
            else {
                text.push_back(temp);
                temp = "";
                i = i + 2;
            }
        }
    }
    // reading from pattern_file.txt and storing it in pattern vector
    ifstream myfile2.open("pattern_file.txt");
    string line;
    while ( getline (myfile2 , line) ) {
        string temp = "";
        for(int i = 0; i < line.length(); ++i) {
            if( line.substr(i,1).compare(" , ") != 0) {   // getting ' , ' then store it
                temp += line[i];
             }
             else {
                pattern.push_back(temp);
                temp = "";
                i = i + 2;
             }
        }
      }
    myfile2.close();
    if( check( text , pattern ) ) {
        cout<<"\nText contains Pattern\n";
    }
    else {
        cout<<"\nText does not contain Pattern\n";
    }
    return 0;
}
