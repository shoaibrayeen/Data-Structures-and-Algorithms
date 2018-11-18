//
//  q9.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 13/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class triathlon {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : class to decide the order to minimize completion time
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : declaring member functions which can ve accessed publicly -
                    mainFunction() -> to decide order
                    display() -> print user's data
                    helper() -> to insert dara and call member functions
     ------------------------------------------------------------------------------------------------
     */
    public:
    int n;
    void mainFunction(vector<vector<int>> &data);
    void display(vector<vector<int>> data);
    void helper();
};

bool selectColumn(const vector<int>& v1, const vector<int>& v2) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : select column by which sorting can be applied -> increasing order
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : false -> decreasing order
                        true -> increasing order
     
     ------------------------------------------------------------------------------------------------
     
     approach    : return bool value which detmines which column has to sorted
     ------------------------------------------------------------------------------------------------
     */
    return v1[1] < v2[1];
}

void triathlon::mainFunction(vector<vector<int>> &data) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : main function to decide the order
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : sorting according to swim time and displaying order
     ------------------------------------------------------------------------------------------------
     */
    sort(data.begin() , data.end() , selectColumn );
    cout << "\nFollowings are the order of contestants for small completion time\n\n";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i][0] << "\t";
    }
    cout << endl;
}

void triathlon::display(vector<vector<int>> data) {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : print the data
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     ------------------------------------------------------------------------------------------------
     
     approach    : displaying using loop
     ------------------------------------------------------------------------------------------------
     */
    cout << "\n-----------------------------------------------------------------";
    cout << "\nContestant Number\t|\tSwim Time\t|\tBike Time\t|\tRun Time\n";
    cout << "-----------------------------------------------------------------\n";
    for ( int i = 0; i < data.size(); i++ ) {
        cout << "\t\t" << data[i][0] << "\t\t\t|\t\t" << data[i][1] << "\t\t|\t\t" << data[i][2] << "\t\t|\t" << data[i][3];
        cout << endl;
    }
    
}

void triathlon::helper() {
    /*
    ------------------------------------------------------------------------------------------------
    
    objective : insert the data and call member functions
    
    ------------------------------------------------------------------------------------------------
    input parameter : none
    
    ------------------------------------------------------------------------------------------------
    
    output parameter : none
    ------------------------------------------------------------------------------------------------
    
    approach    : insertion using loop and then calling member functions
    ------------------------------------------------------------------------------------------------
    */
    
    
    /*
    vector<vector<int>> data{
        { 1 , 52 , 13 , 15} ,
        { 2 , 19 , 17 , 13} ,
        { 3 , 99 , 13 , 10 } ,
        { 4 , 79 , 18 , 17 } ,
        { 5 , 37 , 13 , 14 } ,
        { 6 , 67 , 10 , 14 } ,
        { 7 , 89 , 13 , 19}
    };
    */
    cout << "\nEnter Number of contestants\t:\t";
    cin >> n;
    vector<vector<int>> data(n);
    cout << "\nEnter Value in this form\n";
    cout << "\nSwim Time , Bike Time and then Run Time\n";
    for ( int i = 0; i < n; i++) {
        data[i] = vector<int>(4);
        data[i][0] = i + 1;
        cin >> data[i][1];
        cin >> data[i][2];
        cin >> data[i][3];
    }
    display(data);
    mainFunction(data);
    data.clear();
}

int main() {
    triathlon obj;
    obj.helper();
    return 0;
}
