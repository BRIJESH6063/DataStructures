#include<bits/stdc++.h>
using namespace std ;

// Recursive Implementation ... 
int RodCutting(vector<int> arr, int l, int i) {
    if(i == 0) {
        return l*arr[0] ;
    }
    int notTake = 0 + RodCutting(arr, l, i-1) ;
    int Take = INT_MIN ;
    if(i+1 <= l) Take = arr[i] + RodCutting(arr, l-(i+1), i) ;
    return max(Take, notTake) ;
}

// Memoization Implementation ... 
int RodCutting(vector<int> arr, int l, int i, vector<vector<int>> &dp) {
    if(i == 0) return l*arr[0] ;
    if(dp[i][l] != -1) return dp[i][l] ;
    int notTake = 0 + RodCutting(arr, l, i-1, dp) ;
    int Take = INT_MIN ;
    if(i+1 <= l) Take = arr[i] + RodCutting(arr, l-(i+1), i, dp) ;
    return dp[i][l] = max(Take, notTake) ;
}

// Tabulation Implementation .... 
int RodCutting(vector<int> arr, int l) {
    int n = arr.size() ;
    vector<vector<int>> dp(n, vector<int>(l+1, 0)) ;
    for(int i=0; i<=l; i++) dp[0][i] = i*arr[0] ;
    for(int i=1; i<n; i++) {
        for(int j=0; j<=l; j++) {
            int notTake = 0 + dp[i-1][j] ;
            int Take = INT_MIN ;
            if((i+1) <= j) Take = arr[i] + dp[i][j-(i+1)] ;
            dp[i][j] = max(Take, notTake) ;
        }
    }
    return dp[n-1][l] ;
}


int main()
{
    vector<int> price({2, 5, 7, 7, 8, 10}) ;
    int n = price.size() ;
    int l = 5 ;
    // vector<vector<int>> dp(n, vector<int>(l+1, -1)) ;
    cout << RodCutting(price, l) << endl ;

    return 0 ;
}