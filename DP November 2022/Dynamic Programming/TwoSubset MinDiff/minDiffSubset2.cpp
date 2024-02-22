#include<bits/stdc++.h>
using namespace std ;

int minSubsetSumDiff(vector<int> &a, int n) {
    int totalSum = 0 ;
    for(int i=0; i<n; i++) totalSum += a[i] ;
    int k = totalSum ;

    // Subset sum 2 k Tabulation ... 
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0)) ;
    for(int i=0; i<n; i++) dp[i][0] = true ;
    if(a[0] <= k) dp[0][a[0]] = true ;
    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) {
            bool notTake = dp[i-1][j] ;
            bool take = false ;
            if(j >= a[i]) take = dp[i-1][j-a[i]] ;
            dp[i][j] = (take | notTake) ;
        }
    }

    // dp[n-1][col= 0 -> totalSum]
    int mini = 1e9 ;
    for(int i=0; i<=k; i++) {
        if(dp[n-1][i]) {
            int s1 = i ; int s2 = (k - s1) ;
            mini = min(mini, abs(s1 - s2)) ; 
        }
    }

    return mini ;
}

int main()
{
    vector<int> a({3, 2, 7}) ;
    int n = a.size() ;
    cout << minSubsetSumDiff(a, n) << endl ;
    return 0 ;
}




