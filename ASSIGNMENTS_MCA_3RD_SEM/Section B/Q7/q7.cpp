//
//  q7.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 12/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
struct Interval {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : stucture for buy and sell to store index
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : declaring a structure to store index
     
     ------------------------------------------------------------------------------------------------
     */
    int buy;
    int sell;
};

class stock {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : class to computer order to buy and sell stocks
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : declaring member functions which can be accessed publicly.
                    mainFunction() to compute order to buy and sell stocks
                    insert() which takes input from user
                    helper() which calls member functions
     
     ------------------------------------------------------------------------------------------------
     */
    public:
    int n;
    vector<int> price;
    void insert();
    void mainFunction();
    void helper();
};

void stock::insert() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : insert the data to decide order
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : using loop and push_back() function
     
     ------------------------------------------------------------------------------------------------
     */
    cout << "\nEnter Number of Stocks\t:\t";
    cin >> n;
    int temp;
    cout << "\nEnter Price per share of each Stock on the day\n";
    for ( int i = 0; i < n; i++ ) {
        cin >> temp;
        price.push_back(temp);
    }
}

void stock::mainFunction() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : main function to decide order
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : traversing in price array -> finding local minima and maxima and store it
                    if input is in decreasing order -> return no profit.
     
     ------------------------------------------------------------------------------------------------
     */
    unsigned long n = price.size();
    if (n < 1) {
        return;
    }
    int countSol = 0;
    Interval solution[n/2 + 1];
    int i = 0;
    while (i < n-1) {
        while ((i < n-1) && (price[i+1] <= price[i])) {
            i++;
        }
        if (i == n-1) {
            break;
        }
        solution[countSol].buy = i++;
        while ((i < n) && (price[i] >= price[i-1])) {
            i++;
        }
        solution[countSol].sell = i-1;
        countSol++;
    }
    int totalProfit=0;
    if (countSol == 0) {
        printf("Sorry NO Profit Possibe\n");
    }
    else {
        for (int i = 0; i < countSol; i++) {
            totalProfit += price[solution[i].sell] - price[solution[i].buy];
            cout << "\nBuy on day\t:\t" << solution[i].buy + 1
            << "\t\tSell on day\t:\t" << solution[i].sell + 1
            << "\t\tProfit\t:\t" << price[solution[i].sell]-price[solution[i].buy];
        }
        cout << "\n\nTotal Profit\t:\t" << totalProfit;
    }
}

void stock::helper() {
    /*
     ------------------------------------------------------------------------------------------------
     
     objective : calling member functions
     
     ------------------------------------------------------------------------------------------------
     input parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     output parameter : none
     
     ------------------------------------------------------------------------------------------------
     
     approach    : calling member functions
     
     ------------------------------------------------------------------------------------------------
     */
    insert();
    mainFunction();
}
int main() {
    stock obj;
    obj.helper();
    cout << endl;
    return 0;
}
