#include<bits/stdc++.h>
using namespace std ;

// Recursion Implementation .... 
int KthFrogJump(vector<int> &heights, int k, int n) {
    if(n == 0) return 0 ; 
    int minSteps = INT_MAX ; 

    for(int j=1; j<=k; j++) {
        int jump = INT_MAX ;
        if(n-j >= 0) jump = KthFrogJump(heights, k, n-j) + abs(heights[n] - heights[n-j]) ;
        minSteps = min(minSteps, jump) ;
    }

    return minSteps ;

}

// Memoization Implementation .... 
int KthFrogJump(vector<int> &heights, vector<int> &dp, int k, int n) {
    if(n == 0) return 0 ; 
    int minSteps = INT_MAX ; 
    if(dp[n] != -1) return dp[n] ;
    for(int j=1; j<=k; j++) {
        int jump = INT_MAX ;
        if(n-j >= 0) jump = KthFrogJump(heights, dp, k, n-j) + abs(heights[n] - heights[n-j]) ;
        minSteps = min(minSteps, jump) ;
    }

    return dp[n] = minSteps ;

}

int KthFJTabulation(vector<int> &heights, int k, int n) {
    vector<int> dp(n, -1) ;
    dp[0] = 0 ;
    for(int i=1; i<n; i++) {
        int path = INT_MAX ; 
        for(int j=1; j<=k; j++) {
            int jump = INT_MAX ;
            if(i - j >= 0) jump = dp[i-j] + abs(heights[i] - heights[i-j]) ;
            path = min(path, jump) ; 
        }
        dp[i] = path ;
    }

    return dp[n-1] ;
}

int main()
{
    vector<int> heights({30, 10, 60, 10, 60, 50}) ;
    int n = heights.size() ; int k = 2 ;
    vector<int> dp(n, -1) ;

    // cout << KthFrogJump(heights, k, n-1) << endl ;
    // cout << KthFrogJump(heights, dp, k, n-1) << endl ;

    cout << KthFJTabulation(heights, k, n) << endl ;
    

    return 0 ;
    
}