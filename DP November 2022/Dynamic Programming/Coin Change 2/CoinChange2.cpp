#include<bits/stdc++.h>
using namespace std ;

// Recursive implementation .. 
int CoinChange2(vector<int> &arr, int target, int i) {
    if(i == 0) {
        if(target%arr[0] == 0) return 1 ;
        return 0 ;
    }
    int notTake = CoinChange2(arr, target, i-1) ;
    int Take = 0 ;
    if(arr[i] <= target) Take = CoinChange2(arr, target-arr[i], i) ;
    return Take + notTake ;
}

// Memoization implementation .. 
int CoinChange2(vector<int> &arr, int target, int i, vector<vector<int>> &dp) {
    if(i == 0) {
        if(target%arr[0] == 0) return 1 ;
        return 0 ;
    }
    if(dp[i][target] != -1) return dp[i][target] ;
    int notTake = CoinChange2(arr, target, i-1, dp) ;
    int Take = 0 ;
    if(arr[i] <= target) Take = CoinChange2(arr, target-arr[i], i, dp) ;
    return dp[i][target] = Take + notTake ;
}

// Tabulation Implementation ....
int CoinChange2Tab(vector<int> &arr, int target) {
    int n = arr.size() ;
    vector<vector<int>> dp(n, vector<int>(target+1, 0)) ;
    for(int i=0; i<=target; i++) {
        if(i%arr[0] == 0) dp[0][i] = 1 ;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<=target; j++) {
            int notTake = dp[i-1][j] ;
            int Take = 0 ;
            if(arr[i] <= j) Take = dp[i][j-arr[i]] ;
            dp[i][j]= Take + notTake ;
        }
    }
    return dp[n-1][target] ;
}

int main()
{

    vector<int> arr({1, 2, 3}) ;
    int target = 4 ;
    int n = arr.size() ;
    // vector<vector<int>> dp(n, vector<int>(target+1, -1)) ;
    // cout << CoinChange2(arr, target, n-1, dp) << endl ;
    cout << CoinChange2Tab(arr, target) << endl ;
}