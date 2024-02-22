#include<bits/stdc++.h>
using namespace std ;

// Recursive implementation ..... 
int uniquePath(int i, int j) {
    if(i == 0 && j == 0) return 1 ; 
    if(i < 0 || j < 0) return 0 ;
    int up = uniquePath(i-1, j) ;
    int left = uniquePath(i, j-1) ;
    return left + up ;
}

// Memoization implementation .... 
int uniquePath(int i, int j, vector<vector<int>> &dp) {
    if(i == 0 && j == 0) return 1 ; 
    if(i < 0 || j < 0) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int up = uniquePath(i-1, j, dp) ;
    int left = uniquePath(i, j-1, dp) ;
    return dp[i][j] = left + up ;
}

// Tabulation implementation .... 
int uniquePathT(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0)) ;
    dp[0][0] = 1 ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i ==0 && j == 0) continue ;
            else {
                int up = 0 ; int left = 0 ;
                if(i > 0) up = dp[i-1][j] ;
                if(j > 0) left = dp[i][j-1] ;
                dp[i][j] = up + left ; 
            }
        }
    }
    // for(int i=0; i<m; i++) {
    //     for(int j=0; j<n; j++) cout << dp[i][j] << " " ;
    //     cout << endl ;
    // }
    return dp[m-1][n-1] ;
}

//space optimisation .. 
int uniquePathOpt(int m, int n) {
    vector<int> prev(n, 0) ; 
    for(int i=0; i<m; i++) {
        vector<int> curr(n, 0) ;
        for(int j=0; j<n; j++) {
            if(i == 0 && j == 0) curr[j] = 1 ;
            else {
                int up = 0 ; int left = 0 ;
                if(i > 0) up = prev[j] ;
                if(j > 0) left = curr[j-1] ;
                curr[j] = up + left ;
            } 
        }

        prev = curr ;
    }

    return prev[n-1] ;
}


int main() 
{
    int i = 3 ; int j = 2 ;
    // cout << uniquePath(i-1, j-1) << endl ;
    // vector<vector<int>> dp(i+2, vector<int>(j+2, -1)) ;
    // cout << uniquePath(i, j, dp) << endl ;
    // cout << uniquePathT(i, j) << endl ;
    cout << uniquePathOpt(i, j) << endl ;
    return 0 ;
}