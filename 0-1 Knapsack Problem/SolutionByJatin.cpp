#include<bits/stdc++.h>
using namespace std;
#define int long long unsigned int

typedef vector<int> vi;
#define f(a,b) for(int i =a ; i <b ; i++)
#define PB push_back

signed main(signed argc ,char **argv){
    int n;
    cin>> n;
    vi w(n),v(n);
    f(0,n){
        cin>> v[i];
    }
    f(0,n){
        cin>> w[i];
    }
    int sack =0;
    cin>> sack;
    vector<vector<int>>dp(v.size()+1, (0,vector<int>(sack+1)));
    for(int i =0 ; i< dp.size() ; i++){
        for(int j =0 ; j < dp[0].size() ; j++){
            if(i==0){
                dp[i][j] =0;
            }else if(j== 0){
                dp[i][j]= 0;
            }else
            {
                if(j >= w[i-1]){
                    dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
                }
            }
            
        }
    }
    cout<< dp[v.size()][sack];
  
    return 0;
}
