// at max 2 transactions take place 
#include<bits/stdc++.h>
using namespace std ;

// recursive implementation ...
int BuySellStocksIII(vector<int> &price, int i, int cap, int buy) {
    int n = price.size() ;
    if(i == n || cap == 0) return 0 ;
    int profit = 0 ;
    if(buy) {
        profit = max(-price[i] + BuySellStocksIII(price, i+1, cap, 0),
        0 + BuySellStocksIII(price, i+1, cap, 1)) ;
    }
    else {
        profit = max(price[i] + BuySellStocksIII(price, i+1, cap-1, 1),
        0 + BuySellStocksIII(price, i+1, cap, 0)) ;
    }
    return profit ;
}

// memoization implementation ...
int BuySellStocksIII(vector<int> &price, int i, int cap, int buy, vector<vector<vector<int>>> &dp) {
    int n = price.size() ;
    if(i == n || cap == 0) return 0 ;
    int profit = 0 ;
    if(dp[i][buy][cap] != -1) return dp[i][buy][cap] ;
    if(buy) {
        profit = max(-price[i] + BuySellStocksIII(price, i+1, cap, 0, dp),
        0 + BuySellStocksIII(price, i+1, cap, 1, dp)) ;
    }
    else {
        profit = max(price[i] + BuySellStocksIII(price, i+1, cap-1, 1, dp),
        0 + BuySellStocksIII(price, i+1, cap, 0, dp)) ;
    }
    return dp[i][buy][cap] = profit ;
}

// Tabulation implementation .. 
int BuySellStocksIII(vector<int> &price) {
    int n = price.size() ; int cap = 2 ;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(cap+1, 0))) ;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=1; j++) dp[i][j][0] = 0 ;
    }
    for(int j=0; j<=1; j++){
        for(int k=0; k<=cap; k++) dp[n][j][k] = 0 ;
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=1; j++) {
            for(int k=1; k<=cap; k++) {
                int profit = 0 ;
                if(j) profit = max(-price[i] + dp[i+1][0][k]  , 0 + dp[i+1][1][k]) ;
                else  profit = max( price[i] + dp[i+1][1][k-1], 0 + dp[i+1][0][k]) ;
                dp[i][j][k] = profit ;
            }
        }
    }
    return dp[0][1][2] ;
}

// space optimisation .. 
int BuySellStocksIIIS(vector<int> &price) {
    int n = price.size() ; int cap = 2 ;
    vector<vector<int>> ahead(2, vector<int>(cap+1, 0)) ; 
    vector<vector<int>> curr(2, vector<int>(cap+1, 0)) ; 
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=1; j++) {
            for(int k=1; k<=cap; k++) {
                int profit = 0 ;
                if(j) profit = max(-price[i] + ahead[0][k]  , 0 + ahead[1][k]) ;
                else  profit = max( price[i] + ahead[1][k-1], 0 + ahead[0][k]) ;
                curr[j][k] = profit ;
            }
        }
        ahead = curr ;
    }
    return ahead[1][2] ;
}

int main()
{
    vector<int> arr({3, 5, 3, 0, 0, 3, 1, 4}) ;
    // int n = arr.size() ; int cap = 2 ;
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap+1, -1))) ;
    // cout << BuySellStocksIII(arr, 0, cap, 1, dp) << endl ;
    cout << BuySellStocksIIIS(arr) << endl ;
    return 0 ;
}