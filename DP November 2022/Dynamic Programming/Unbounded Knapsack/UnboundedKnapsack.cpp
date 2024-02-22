#include<bits/stdc++.h>
using namespace std ;

// Recursion Implementation .. 
int UnboundedKnapsack(vector<int> &w, vector<int> &v, int wt, int i) {
    if(i == 0) {
        return (wt/w[0])*v[0] ;
    }
    int notTake = 0 + UnboundedKnapsack(w, v, wt, i-1) ;
    int Take = INT_MIN ;
    if(w[i] <= wt) Take = v[i] + UnboundedKnapsack(w, v, wt-w[i], i) ;
    return max(Take, notTake) ;
}

// Memoization implementation ....
int UnboundedKnapsack(vector<int> &w, vector<int> &v, int wt, int i, vector<vector<int>> &dp) {
    if(i == 0) {
        return (wt/w[0])*v[0] ;
    }
    if(dp[i][wt] != -1) return dp[i][wt] ;
    int notTake = 0 + UnboundedKnapsack(w, v, wt, i-1, dp) ;
    int Take = INT_MIN ;
    if(w[i] <= wt) Take = v[i] + UnboundedKnapsack(w, v, wt-w[i], i, dp) ;
    return dp[i][wt] = max(Take, notTake) ;
}

// Tabulation Implementation ... 
int UnboundedKnapsack(vector<int> &w, vector<int> &v, int wt) {
    int n = w.size() ;
    vector<vector<int>> dp(n, vector<int>(wt+1, 0)) ;
    for(int i=0; i<=wt; i++) dp[0][i] = (i/w[0])*v[0] ;
    for(int i=1; i<n; i++) {
        for(int j=0; j<= wt; j++) {
            int notTake = 0 + dp[i-1][j] ;
            int Take = INT_MIN ;
            if(w[i] <= j) Take = v[i] + dp[i][j-w[i]] ;
            dp[i][j] = max(Take, notTake) ;
        }
    }
    return dp[n-1][wt] ;
}

int main()
{
    vector<int> w({2, 4, 6}) ;
    vector<int> v({5, 11, 13}) ;
    int wt = 4 ;
    int n = w.size() ;
    vector<vector<int>> dp(n, vector<int>(wt+1, -1)) ;
    cout << UnboundedKnapsack(w, v, wt) << endl ;
    return 0 ;
}