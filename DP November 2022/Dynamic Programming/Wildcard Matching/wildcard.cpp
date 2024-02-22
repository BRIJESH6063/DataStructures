// wildcard matching leetcode problem (pattern matching.)
// ? --> single character match
// * --> matches with sequence of lengt 0 or more.. 
#include<bits/stdc++.h>
using namespace std ;

// recursive implementation ... 
bool wildcard(string s, string t, int i, int j) {
    if(i < 0 && j < 0)  return true ;
    if(i < 0 && j >= 0) return false ;
    if(i >= 0 && j < 0) return false ; 
    if(s[i] == t[j] || s[i] == '?') return wildcard(s, t, i-1, j-1) ;
    if(s[i] == '*') return wildcard(s, t, i, j-1) || wildcard(s, t, i-1, j) ;
    return false ;
}

// memoization implemenation ... 
bool wildcard(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if(i < 0 && j < 0)  return true ;
    if(i < 0 && j >= 0) return false ;
    if(i >= 0 && j < 0) return false ; 
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s[i] == t[j] || s[i] == '?') return dp[i][j] = wildcard(s, t, i-1, j-1, dp) ;
    if(s[i] == '*') return dp[i][j] = wildcard(s, t, i, j-1, dp) || wildcard(s, t, i-1, j, dp) ;
    return false ;
}

// Tabulation Implemenattion ...
// bool wildcard(string s, string t, int i, int j, vector<vector<int>> &dp) {
//     int n = s.size() ; int m = t.size() ;
//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
//     dp[0][0] = true ;

// }

int main()
{
    string s = "*a" ;
    string t = "aa" ;
    int n = s.size() ; int m = t.size() ;
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    if(wildcard(s, t, n-1, m-1)) cout << "True" << endl ;
    else cout << "False" << endl ;
    return 0 ;
}