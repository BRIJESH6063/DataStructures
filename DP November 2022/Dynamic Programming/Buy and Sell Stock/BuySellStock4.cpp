// at most k transaction ..  
#include<bits/stdc++.h>
using namespace std ;

// recursive implementation ... failed ... 
int BuySellStocksIV(vector<int> &price, int i, int cap, int transNo) {
    int n = price.size() ;
    if(i == n || transNo == 2*cap) return 0 ;
    int profit = 0 ;
    if(transNo%2 == 0) return max(-price[i] + BuySellStocksIV(price, i+1, cap, transNo+1),
        0 + BuySellStocksIV(price, i+1, cap, transNo)) ;
    else return max(price[i] + BuySellStocksIV(price, i+1, cap, transNo+1),
        0 + BuySellStocksIV(price, i+1, cap, transNo)) ;
}

// memoization implementation ..  failed ...
int BuySellStocksIV(vector<int> &price, int i, int cap, int transNo, vector<vector<int>> &dp) {
    int n = price.size() ;
    if(i == n || transNo == 2*cap) return 0 ;
    int profit = 0 ;
    if(transNo%2 == 0) return dp[i][transNo] = max(-price[i] + BuySellStocksIV(price, i+1, cap, transNo+1, dp),
        0 + BuySellStocksIV(price, i+1, cap, transNo, dp)) ;
    else return dp[i][transNo] = max(price[i] + BuySellStocksIV(price, i+1, cap, transNo+1, dp),
        0 + BuySellStocksIV(price, i+1, cap, transNo, dp)) ;

}

// Tabulation Implementation ...
// int BuySellStockIV(vector<int> &price, int k) {
//     int n = price.size() ;
//     vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0)) ;
//     for(int i=n-1; i>=0; i--) {
//         for(int j=2*k-1; j>=0; j--) {
//             if(j%2 == 0) dp[i][j] = max(-price[i] + dp[i+1][j+1], 0 + dp[i+1][j]) ;
//             else dp[i][j] = max(price[i] + dp[i+1][j+1], 0 + dp[i+1][j]) ; 
//         }
//     } 
//     return dp[0][0] ;
// }


// space optimisation ...
int BuySellStockIV(vector<int> &price, int k) {
    int n = price.size() ;
    // vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0)) ;
    vector<int> ahead(2*k+1, 0) ; vector<int> curr(2*k+1, 0) ;
    for(int i=n-1; i>=0; i--) {
        for(int j=2*k-1; j>=0; j--) {
            if(j%2 == 0) curr[j] = max(-price[i] + ahead[j+1], 0 + ahead[j]) ;
            else curr[j] = max(price[i] + ahead[j+1], 0 + ahead[j]) ; 
        }
        ahead = curr ;
    } 
    return curr[0] ;
}

int main()
{
    vector<int> arr({2, 5, 10, 8, 12}) ;
    int n = arr.size() ; int k = 2 ;
    vector<vector<int>> dp(n, vector<int>(2*k, -1)) ;
    cout << BuySellStocksIV(arr, 0, k, 0) << endl ;
    // cout << BuySellStockIV(arr, k) << endl ;
    return 0 ;
}