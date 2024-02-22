#include<bits/stdc++.h>
using namespace std ;

// Recursion implementation 
int knapsack01(vector<int> &w, vector<int> &v, int wt, int i) {
    if(i == 0) {
        if(w[i] <= wt) return v[i] ;
        return 0 ;
    }
    int notTake = 0 + knapsack01(w, v, wt, i-1) ;
    int Take = INT_MIN ;
    if(w[i] <= wt) Take = v[i] + knapsack01(w, v, wt-w[i], i-1) ;
    return max(Take, notTake) ;
}

// memoization implementation ...
int knapsack01(vector<int> &w, vector<int> &v, int wt, int i, vector<vector<int>> &dp) {
    if(i == 0) {
        if(w[i] <= wt) return v[i] ;
        return 0 ;
    }
    if(dp[i][wt] != -1) return dp[i][wt] ;
    int notTake = 0 + knapsack01(w, v, wt, i-1) ;
    int Take = INT_MIN ;
    if(w[i] <= wt) Take = v[i] + knapsack01(w, v, wt-w[i], i-1) ;
    return dp[i][wt] = max(Take, notTake) ;
}

// Tabulation implementation ..
int knapsack01Tab(vector<int> &w, vector<int> &v, int wt) {
    int n = w.size() ;
    vector<vector<int>> dp(n, vector<int>(wt+1, 0)) ;
    for(int i=w[0]; i<=wt; i++) dp[0][i] = v[0] ;
    for(int i=1; i<n; i++) {
        for(int j=0; j<=wt; j++) {
            int Take = dp[i-1][j] ;
            int notTake = INT_MIN ; //
            if(j >= w[i]) notTake = v[i] + dp[i-1][j-w[i]] ;
            dp[i][j] = max(Take, notTake) ;
        }
    }
    return dp[n-1][wt] ;
}

int main()
{
    vector<int> w({3, 2, 5}) ;
    vector<int> v({30, 40, 60}) ;
    int wt = 6 ; int n = w.size() ;
    vector<vector<int>> dp(n, vector<int>(wt+1, -1)) ;
    // cout << knapsack01(w, v, wt, n-1) << endl ;
    // cout << knapsack01(w, v, wt, n-1, dp) << endl ;
    cout << knapsack01Tab(w, v, wt) << endl ;
    return 0 ;
}