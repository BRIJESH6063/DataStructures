#include<bits/stdc++.h>
using namespace std ;

// Recursive Implementation .... 
int NAdjSum(vector<int> &arr, int i) {
    if(i == 0) return arr[0] ;
    if(i < 0) return 0 ;
    int pick = arr[i] + NAdjSum(arr, i-2) ;
    int npick = NAdjSum(arr, i-1) ;
    return max(pick, npick) ;
}

// Memoization Implementation .... 
int NAdjSum(vector<int> &arr, vector<int> &dp, int i) {
    if(i == 0) return arr[0] ;
    if(i < 0) return 0 ;
    if(dp[i] != -1) return dp[i] ;
    int pick = arr[i] + NAdjSum(arr, dp, i-2) ;
    int npick = NAdjSum(arr, dp,  i-1) ;
    return dp[i] = max(pick, npick) ;
}

// Tabulation Method Implementation ... 
int NAdjSumT(vector<int> &arr, int n) {
    vector<int> dp(n, -1) ;
    dp[0] = arr[0] ;
    for(int i=1; i<n; i++) {
        int npick = dp[i-1] ;
        int pick = arr[i] ;
        if(i > 1) pick += dp[i-2] ;
        dp[i] = max(pick, npick) ;
    }


    return dp[n-1] ;
}

// Space optimisation possible .... 

int main() 
{
    vector<int> arr({2, 1, 4, 9}) ;
    // cout << NAdjSum(arr, arr.size()-1) << endl ;
    int n = arr.size() ; vector<int> dp(n, -1) ;
    // cout << NAdjSum(arr, dp, n-1) << endl ;
    cout << NAdjSumT(arr, n) << endl ;
    return 0 ;
}


