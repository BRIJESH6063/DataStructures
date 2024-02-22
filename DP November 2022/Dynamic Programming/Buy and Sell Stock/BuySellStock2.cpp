// Buy and sell Stock multiple times and make maximum profit..
#include<bits/stdc++.h>
using namespace std ;

// recursion implementation ... 
int BuySellStocksII(vector<int> &price, int i, int buy) {
    int n = price.size() ;
    if(i == n) return 0 ;
    int profit = 0 ;
    if(buy) {
        profit = max(-price[i] + BuySellStocksII(price, i+1, 0),
        0 + BuySellStocksII(price, i+1, 1)) ;
    }
    else {
        profit = max(price[i] + BuySellStocksII(price, i+1, 1),
        0 + BuySellStocksII(price, i+1, 0)) ;
    }
    return profit ;
}

// memoization implementation1 ... 
int BuySellStocksII(vector<int> &price, int i, int buy, vector<vector<int>> &dp) {
    int n = price.size() ;
    if(i == n) return 0 ;
    if(dp[i][buy] != -1) return dp[i][buy] ;
    int profit = 0 ;
    if(buy) {
        profit = max(-price[i] + BuySellStocksII(price, i+1, 0, dp),
        0 + BuySellStocksII(price, i+1, 1, dp)) ;
    }
    else {
        profit = max(price[i] + BuySellStocksII(price, i+1, 1, dp),
        0 + BuySellStocksII(price, i+1, 0, dp)) ;
    }
    return dp[i][buy] = profit ;
}

// memoization implementation 2 ... 
long BuySellStocksII(long *price, int i, int buy, vector<vector<long>> &dp) {
    int n = sizeof(price)/sizeof(price[0]) ;
    if(i == n) return 0 ;
    if(dp[i][buy] != -1) return dp[i][buy] ;
    long profit = 0 ;
    if(buy) {
        profit = max(-price[i] + BuySellStocksII(price, i+1, 0, dp),
        0 + BuySellStocksII(price, i+1, 1, dp)) ;
    }
    else {
        profit = max(price[i] + BuySellStocksII(price, i+1, 1, dp),
        0 + BuySellStocksII(price, i+1, 0, dp)) ;
    }
    return dp[i][buy] = profit ;
}

// Tabulation implementation ..
int BuySellStocksII(vector<int> &price) {
    int n = price.size() ;
    vector<vector<int>> dp(n+1, vector<int>(2, 0)) ;
    dp[n][0] = dp[n][1] = 0 ;
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=1; j++) {
            int profit = 0 ;
            if(j) profit = max(-price[i] + dp[i+1][0], 0 + dp[i+1][1] ) ;
            else profit = max(price[i] + dp[i+1][1], 0 + dp[i+1][0]) ;
            dp[i][j] = (int)profit ;
        }
    }
    return dp[0][1] ;
}

// space optimisation ...
int BuySellStocksIIS(vector<int> &price) {
    int n = price.size() ;
    vector<int> ahead(2, 0) ; vector<int> curr(2, 0) ;
    ahead[0] = ahead[1] = 0 ;
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=1; j++) {
            int profit = 0 ;
            if(j) profit = max(-price[i] + ahead[0], 0 + ahead[1] ) ;
            else profit = max(price[i] + ahead[1], 0 + ahead[0]) ;
            curr[j] = (int)profit ;
        }
        ahead = curr ;
    }
    return ahead[1] ;
}

int main()
{
    vector<int> arr({7, 1, 5, 3, 6, 4}) ;
    // long arr[] = {7, 1, 5, 3, 6, 4} ;
    int n = arr.size() ;
    vector<vector<long>> dp(n, vector<long>(2, -1)) ;
    cout << BuySellStocksIIS(arr) << endl ;
    return 0 ;
}