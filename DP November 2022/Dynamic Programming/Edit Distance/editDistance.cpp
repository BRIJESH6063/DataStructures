// minimum number of operations to convert string1 to string2
// operations -- 1. insert 2. remove 3. replace
#include<bits/stdc++.h>
using namespace std ;

// recursive implementation ... 
int editDistance(string s, string t, int i, int j) {
    cout << i << "  " << j << endl ;
    if(i < 0) return j+1 ;
    if(j < 0) return i+1 ;
    if(s[i] == t[j]) return editDistance(s, t, i-1, j-1) ;
    else {
        return min(1 + editDistance(s, t, i, j-1), min(1 + editDistance(s, t, i-1, j)
        , 1 + editDistance(s, t, i-1, j-1))) ;
    }
}

// memoization implementation ... 
int editDistance(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if(i < 0) return j+1 ;
    if(j < 0) return i+1 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s[i] == t[j]) return dp[i][j] = editDistance(s, t, i-1, j-1, dp) ;
    else {
        return dp[i][j] = min(1 + editDistance(s, t, i, j-1, dp), min(1 + editDistance(s, t, i-1, j, dp)
        , 1 + editDistance(s, t, i-1, j-1, dp))) ;
    }
}

// Tabulation implementation ..
int editDistance(string s, string t) {
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
    for(int i=0; i<=n; i++) dp[i][0] = i ;
    for(int j=0; j<=m; j++) dp[0][j] = j ;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] ;
            else dp[i][j] = min(1 + dp[i][j-1], min(1 + dp[i-1][j], 1 + dp[i-1][j-1])) ;
        }
    }
    return dp[n][m] ;
}


int main()
{
    string s = "horse" ;
    string t = "ros" ;
    int n = s.size() ; int m = t.size() ;
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    // cout << editDistance(s, t, n-1, m-1, dp) << endl ;
    cout << editDistance(s, t) << endl ;

    return 0 ;
}