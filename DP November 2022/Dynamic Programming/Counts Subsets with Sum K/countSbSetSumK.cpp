#include<bits/stdc++.h>
using namespace std ;

// Recurrence implementation .... 
int countSubsetSumK(vector<int> &a, int i, int s) {
    if(s == 0) return 1 ;
    if(i == 0) return (a[i] == s) ;
    int notPick = countSubsetSumK(a, i-1, s) ;
    int pick = 0 ;
    if(a[i] <= s) pick = countSubsetSumK(a, i-1, s-a[i]) ;
    return pick + notPick ;
}

// Memoization implementation .... 
int countSubsetSumK(vector<int> &a, int i, int s, vector<vector<int>> &dp) {
    if(s == 0) return 1 ;
    if(i == 0) return (a[i] == s) ;
    if(dp[i][s] != -1) return dp[i][s] ;
    int notPick = countSubsetSumK(a, i-1, s, dp) ;
    int pick = 0 ;
    if(a[i] <= s) pick = countSubsetSumK(a, i-1, s-a[i], dp) ;
    return dp[i][s] = pick + notPick ;
}

// Tabulation implementation .... 
int countSubsetSumKTab(vector<int> &a, int s) {
    int n = a.size() ;
    vector<vector<int>> dp(n, vector<int>(s+1, 0)) ;
    for(int i=0; i<n; i++) dp[i][0] = 1 ;
    if(a[0] <= s) dp[0][a[0]] = 1 ;
    for(int i=1; i<n; i++) {
        for(int j=0; j<=s; j++) {
            int notTake = dp[i-1][j] ;
            int take = 0 ;
            if(a[i] <= j) take = dp[i-1][j-a[i]] ;
            dp[i][j] = take + notTake ;
        }
    }
    return dp[n-1][s] ;
}




int main()
{
    vector<int> a({1, 2, 2}) ; int s = 3 ;
    // int n = a.size() ;
    // vector<vector<int>> dp(n, vector<int>(s+1, -1)) ;
    // cout << countSubsetSumK(a, n-1, s, dp) << endl ;

    // int t ; cin >> t ;
    // while(t--) {
    //     int n ; cin >> n ; int s ; cin >> s ;
    //     int x ; vector<int> a ;
    //     vector<vector<int>> dp(n, vector<int>(s+1, -1)) ;
    //     for(int i=0; i<n; i++) {
    //         cin >> x ; a.push_back(x) ;
    //     }
    //     cout << countSubsetSumK(a, n-1, s, dp) << endl ;
    // }

    cout << countSubsetSumKTab(a, s) << endl ;
    return 0 ;
}