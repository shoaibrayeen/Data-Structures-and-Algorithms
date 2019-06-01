//
//  code_1.cpp
//  Data Structure
//
//  Created by Mohd Shoaib Rayeen on 19/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int helperMask(int number) {
	int mask = 0;
	for ( int i = 1; number/i; i*=10 ) {
		int digit = number/i % 10;
		mask |= 1 << digit;
	}
	return mask;
}

int mainFunction(int i, int memo[1<<10], vector<int> & arr) {
	if( i == 0) {
		return memo[i] = 0;
	}
	if ( memo[i] != -1) {
		return memo[i];
	}
	int res  = 0;
	for ( auto number: arr) {
		int mask = helperMask(number);
		if ( (i | mask) == i) {
			res = max( mainFunction(i ^ helperMask(number) , memo , arr ) + number , res);
		}
	}
	return memo[i] = res;
 }
 
int main() {
	int t , n;
	cin >> t;
	for ( int p = 0; p < t; p++) {
		cin >> n;
		vector<int> arr(n);
		for( int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int memo[1024];
		for( int i = 0; i < 1024; i++) {
			memo[i] = -1;
		}
		int result = 0;
		for( int i = 0; i < 1024; i++) {
			result = max( result , mainFunction(i , memo , arr));
		}
		cout << result << "\n";
	}
}
