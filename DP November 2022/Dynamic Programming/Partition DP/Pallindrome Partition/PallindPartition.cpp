#include<bits/stdc++.h>
using namespace std ;


bool isPallindrome(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false ;
        i++ ; j-- ;
    }
    
    return true ;
}

// Recursion Implementation 
int PallindromePart(string s, int i) {
    int n = s.size() ;
    if(i == n) return 0 ;
    int min_cost = INT_MAX ;
    for(int j=i; j<n; j++) {
        if(isPallindrome(s, i, j)) {
            int cost = 1 + PallindromePart(s, j+1) ;
            min_cost = min(min_cost, cost) ;
        }
    }
    return min_cost ;
}

// memoization implementation ...
int PallinPartition(string s, int i, vector<int> &dp) {
    int n = s.size() ;
    if(i == n) return 0 ;
    if(dp[i] != -1) return dp[i] ;
    int min_cost = INT_MAX ;
    for(int j=i; j<n; j++) {
        if(isPallindrome(s, i, j)) {
            int cost = 1 + PallinPartition(s, j+1, dp) ;
            min_cost = min(min_cost, cost ) ;
        }
    }
    return dp[i] = min_cost ;
}
int main()
{
    string s = "NITIN" ;
    int n = s.size() ;
    vector<int> dp(n+1, -1) ;
    cout << PallinPartition(s, 0, dp)-1 << endl ;

    return 0 ;
}