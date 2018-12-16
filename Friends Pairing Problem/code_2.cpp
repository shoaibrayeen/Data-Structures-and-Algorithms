//
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

int countFriendsPairings(int n) {
    if ( n <= 2 ) {
        return n;
    }
    return countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2);
}


int main() {
    int n;
    cout << "\nEnter Number of People\t\t:\t";
    cin >> n;
    cout << "Number of Different Pairs\t:\t" << countFriendsPairings(n) << endl;
    return 0;
}
