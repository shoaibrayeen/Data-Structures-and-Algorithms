#include <bits/stdc++.h> 
using namespace std; 
  
int maxGameByWinner(int N) { 
    int dp[N]; 
    dp[0] = 1;     
    dp[1] = 2; 
    int i = 2; 
    do { 
        dp[i] = dp[i - 1] + dp[i - 2]; 
    } while (dp[i++] <= N); 
  
    return (i - 2); 
} 
 
int main() { 
    int N;
    cout << "\nEnter N\t:\t";
    cin >> N; 
    cout << maxGameByWinner(N) << endl; 
    return 0; 
} 
