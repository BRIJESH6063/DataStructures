// Given two strings s and t, return the number of distinct subsequences of s which equals t.
#include<bits/stdc++.h>
using namespace std ;

// Recursive Implementation ... 
int DistinctSubsequence(string &s, string t, int i, int j) {
    if(j < 0) return 1 ;
    if(i < 0) return 0 ;
    if(s[i] == t[j]) return DistinctSubsequence(s, t, i-1, j-1) + DistinctSubsequence(s, t, i-1, j) ;
    else return DistinctSubsequence(s, t, i-1, j) ;
}

// Memoization Implementation ... 
int DistinctSubsequence(string &s, string t, int i, int j, vector<vector<int>> &dp) {
    if(j < 0) return 1 ;
    if(i < 0) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s[i] == t[j]) return dp[i][j] = DistinctSubsequence(s, t, i-1, j-1, dp) + DistinctSubsequence(s, t, i-1, j, dp) ;
    else return dp[i][j] = DistinctSubsequence(s, t, i-1, j, dp) ;
}

// Tabulation Implementation .... 
int DistinctSubsequence(string &s, string t) {
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
    for(int i=0; i<=n; i++) dp[i][0] = 1 ;
    for(int i=1; i<=m; i++) dp[0][i] = 0 ;
    for(int i=1; i<=n; i++){ 
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ;
            else dp[i][j] = dp[i-1][j] ;
        }
    }
    return dp[n][m] ;
}

int main()
{
    string s = "bbb" ;
    string t = "bb" ;
    int n = s.size() ; int m = t.size() ;
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    // cout << DistinctSubsequence(s, t, n-1, m-1, dp) << endl ;
    cout << DistinctSubsequence(s, t) << endl ;

    return 0 ;
}