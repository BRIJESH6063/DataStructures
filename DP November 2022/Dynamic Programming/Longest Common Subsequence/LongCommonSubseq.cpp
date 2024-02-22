#include<bits/stdc++.h>
using namespace std ;

// Recursive Implementation .... 
int LCS(string s1, string s2, int i1, int i2) {
    if(i1 < 0 || i2 < 0) return 0 ;
    if(s1[i1] == s2[i2]) return 1 + LCS(s1, s2, i1-1, i2-1) ;
    return max(LCS(s1, s2, i1-1, i2), LCS(s1, s2, i1, i2-1)) ;
}

// Memoization Implementation ...
int LCS(string s1, string s2, int i1, int i2, vector<vector<int>> &dp) {
    if(i1 < 0 || i2 < 0) return 0 ;
    if(dp[i1][i2] != -1) return dp[i1][i2] ;
    if(s1[i1] == s2[i2]) return dp[i1][i2] =  1 + LCS(s1, s2, i1-1, i2-1, dp) ;
    return dp[i1][i2] = max(LCS(s1, s2, i1-1, i2, dp), LCS(s1, s2, i1, i2-1, dp)) ;
}

// Tabulation Implementation .. 
int LCS(string s1, string s2) {
    int n1 = s1.size() ; int n2 = s2.size() ;
    // Requires shifting of index since -1 index is invalid .. 
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)) ;
    for(int i=0; i<=n1; i++) dp[i][0] = 0 ;
    for(int i=0; i<=n2; i++) dp[0][i] = 0 ;
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1] ;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
        }
    }
    return dp[n1][n2] ;
}

int main()
{
    string s1 = "acd" ;
    string s2 = "ced" ;
    int n1 = s1.size() ; int n2 = s2.size() ;
    vector<vector<int>> dp(n1, vector<int>(n2, -1)) ;
    cout << LCS(s1, s2, n1-1, n2-1, dp) << endl ;
    return 0 ;
}

