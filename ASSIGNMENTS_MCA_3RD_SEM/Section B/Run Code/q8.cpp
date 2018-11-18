//
//  q8.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class priceGrowth {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : class to computer order to buy licence
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : declaring member functions which can be accessed publicly.
                    mainFunction() to decide order
                    insert() which takes input from user
                    helper() which calls member fucntions
     
     ------------------------------------------------------------------------------------------------
     */
    public:
    int n;
    void mainFunction(vector<vector<int>> &data);
    void display(vector<vector<int>> data);
    void helper();
    
};


void priceGrowth::helper() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insertion in 2D Vector and call member functions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     */
     int n;
     cout << "\nEnter Total Number of Licences\t:\t";
     cin >> n;
     vector<vector<int>> data(n);
     cout << "\nEnter Price Growth\n";
     for ( int i = 0; i < n; i++) {
     data[i] = vector<int>(2);
     data[i][0] = i + 1;
     cin >> data[i][1];
     }
    /*
    vector<vector<int>> data{
        { 1 , 95}  ,
        { 2 , 13}  ,
        { 3 , 10 } ,
        { 4 , 17 } ,
        { 5 , 34 } ,
        { 6 , 18 } ,
        { 7 , 89}  ,
        { 8 , 19} ,
        { 9 , 99 }
    };
     */
    display(data);
    mainFunction(data);
    data.clear();
}
bool selectColumn(const vector<int>& v1, const vector<int>& v2) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : select column by which sorting can be applied -> decreasing order
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : true -> decreasing order
                        false -> increasing order
     
     ------------------------------------------------------------------------------------------------
     
     approach    : return bool value which detmines which column has to sorted
     ------------------------------------------------------------------------------------------------
     */
    return v1[1] > v2[1];
}

void priceGrowth::mainFunction(vector<vector<int>> &data) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : to computer order
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : sort 2D Vector according to Cost
     
     ------------------------------------------------------------------------------------------------
     */
    sort(data.begin() , data.end() , selectColumn);
    cout << "\n-------------------------------------------";
    cout << "\nPurchased Month\t|\tLicense#\t|\tCost\n";
    cout << "-------------------------------------------\n";
    int month = 1;
    int temp = 0;
    for( int i = 0; i < data.size(); i++ ) {
        temp = 100*data[i][1]*month;
        if ( month == 1) {
            temp = 100;
        }
        cout << "\t\t" << month << "\t\t|\t\t" << data[i][0] << "\t\t|\t" << temp;
        cout << endl;
        month++;
    }
}

void priceGrowth::display(vector<vector<int>> data) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : displaying details
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\n--------------------------------";
    cout << "\n  Licence#\t|\tPrice Growth\n";
    cout << "--------------------------------\n";
    for( int i = 0; i < data.size(); i++ ) {
        cout << "\t\t" << data[i][0] << "\t|\t\t" << data[i][1];
        cout << endl;
    }
}

/*
int main() {
    priceGrowth obj;
    obj.helper();
    cout << endl;
    return 0;
}
*/
