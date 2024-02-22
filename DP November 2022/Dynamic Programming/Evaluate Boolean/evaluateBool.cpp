#include<bits/stdc++.h>
using namespace std ;

// recurrence implemenattion ..
int evaluateBool(string s, int i, int j, int isTrue, vector<vector<int>> &dp) {
    if(i>j) return 0 ;
    if(i == j) {
        if(isTrue ) return s[i] == 'T' ;
        else return s[i] == 'F' ;
    }
    if(dp[i][j] != -1) return dp[i][j] ;
    int ways = 0 ;
    for(int ind=i+1; ind<=j-1; ind++) {
        int lT = evaluateBool(s, i, ind-1, 1, dp) ;
        int lF = evaluateBool(s, i, ind-1, 0, dp) ;
        int rT = evaluateBool(s, ind+1, j, 1, dp) ;
        int rF = evaluateBool(s, ind+1, j, 0, dp) ;
        if(s[ind] == '&') {
            if(isTrue) ways += lT*rT ;
            else ways += (lT*rF + lF*rT + lF*rF) ;
        }
        else if(s[ind] == '|') {
            if(isTrue) ways += (lT*rF + lF*rT + lF*rF) ;
            else ways += lF*rF ;
        }
        else {
            if(isTrue) ways += (lT*rF + lF*rT) ;
            else ways += (lT*rT + lF*rF) ;
        }
    }
    return  dp[i][j] = ways ;
}

int main()
{
    string s = "T|T&F&T" ;
    int n = s.size() ;
    vector<vector<int>> dp((n-1)/2, vector<int>((n-1)/2, -1)) ;
    cout << evaluateBool(s, 0, n-1, 1, dp) << endl ;
    for(auto x : dp) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }
    return 0 ;
}




