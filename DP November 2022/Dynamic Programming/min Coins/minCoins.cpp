#include<bits/stdc++.h>
using namespace std ;

// Recursion implementation .. 
int minCoins(vector<int> &coins, int target, int i) {
    int n = coins.size() ;
    if(i == 0) {
        if(target % coins[0] == 0) return target / coins[0] ;
        return INT_MAX ;
    }
    int notTake = 0 + minCoins(coins, target, i-1) ;
    int Take = INT_MAX ;
    if(target >= coins[i]) Take = 1 + minCoins(coins, target-coins[i], i) ;
    return min(Take, notTake) ; 
}

// Memoization implementation ...
int minCoins(vector<int> &coins, int target, int i, vector<vector<int>> &dp) {
    int n = coins.size() ;
    if(i == 0) {
        if(target % coins[0] == 0) return target / coins[0] ;
        return INT_MAX ;
    }
    if(dp[i][target] != -1) return dp[i][target] ;
    int notTake = 0 + minCoins(coins, target, i-1, dp) ;
    int Take = INT_MAX ;
    if(target >= coins[i]) Take = 1 + minCoins(coins, target-coins[i], i, dp) ;
    return dp[i][target] = min(Take, notTake) ; 
}

// Tabulation Implementation
int minCoinsTab(vector<int> &coins, int target) {
    int n = coins.size() ;
    vector<vector<int>> dp(n, vector<int>(target+1, 0)) ;
    for(int i=0; i<=target; i++) {
        if(i % coins[0] == 0) dp[0][i] = i/coins[0] ;
        else dp[0][i] = INT_MAX ;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<= target; j++) {
            int Take = dp[i-1][j] ;
            int notTake = INT_MAX ;
            if(coins[i] <= j) {
                int x = dp[i][j-coins[i]] ;
                if(x == INT_MAX) notTake = INT_MAX ;
                else notTake = x + 1 ;
            }

            dp[i][j] = min(Take, notTake) ;
        }
    }
    return dp[n-1][target] ;
}

int main()
{
    vector<int> coins({9, 6, 5, 1}) ;
    sort(coins.begin(), coins.end()) ;
    int n = coins.size() ; int target = 11 ;
    // vector<vector<int>> dp(n, vector<int>(target+1, -1)) ;
    // cout << minCoins(coins, target, n-1, dp) << endl ;
    cout << minCoinsTab(coins, target) << endl ;
    return 0 ;
}