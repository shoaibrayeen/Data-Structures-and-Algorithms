#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k , int p ) { 
    int C[n+1][k+1]; 
    int i, j; 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = (C[i-1][j-1]%p + C[i-1][j]%p)%p; 
        } 
    } 
  
    return C[n][k]; 
}
 
 
int main () {
    cout << "\nEnter n\t:\t";
    int n;
    cin >> n;
    cout << "\nEnter k\t:\t";
    int k;
    cin >> k;
    cout << "\nEnter p\t:\t";
    int p;
    cin >> p;
    cout <<"\nThe result is\t:\t" << binomialCoeff(n,k,p);
    cout << endl;
    return 0;
}
