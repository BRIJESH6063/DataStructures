// Shortest common supersequence 
#include<bits/stdc++.h>
using namespace std ;

// Tabulation Subsequebnce 
string LCSuperSeq(string s1, string s2) {
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
    
    int i = n1 ; int j = n2 ; string ans = "" ;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans.push_back(s1[i-1]) ; 
            i-- ; j-- ;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            ans += s1[i-1] ; i-- ;
        }
        else {
            ans += s2[j-1] ; j-- ;
        }
    } 
    while(i > 0) { ans += s1[i-1] ; i-- ; }
    while(j > 0) { ans += s2[j-1] ; j-- ; }

    reverse(ans.begin(), ans.end()) ;
    return ans ;
}

int main()
{
    string s = "brute" ;
    string t = "groot" ;
    cout << LCSuperSeq(s, t) << endl ;

    return 0 ;
}
