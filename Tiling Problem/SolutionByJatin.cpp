// problem statement
// Input n = 3
// Output: 3
// Explanation:
// We need 3 tiles to tile the board of size  2 x 3. 
// We can tile the board using following ways
// 1) Place all 3 tiles vertically. 
// 2) Place first tile vertically and remaining 2 tiles horizontally.
// 3) Place first 2 tiles horizontally and remaining tiles vertically

// Input n = 4
// Output: 5
// Explanation:
// For a 2 x 4 board, there are 5 ways
// 1) All 4 vertical
// 2) All 4 horizontal
// 3) First 2 vertical, remaining 2 horizontal
// 4) First 2 horizontal, remaining 2 vertical
// 5) Corner 2 vertical, middle 2 horizontal


#include<bits/stdc++.h>
using namespace std;
//find no of ways to tile 2*w rectangle with 2*1 tile
int find_tile(int w){
    if(w== 1){
        return 1;
    }else if(w== 2){
        return 2;
    }
    return find_tile(w-1)+ find_tile(w-2);
}
int main(int argc ,char **argv){
    int w;
    int h = 2;
    cin>> w;
    
    cout<< find_tile(w);
    vector<int> dp(w+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i =3 ; i< dp.size() ; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    cout<< dp[w];
return 0;
}
