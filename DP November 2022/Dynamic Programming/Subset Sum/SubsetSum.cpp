#include<bits/stdc++.h>
using namespace std ;

// Recursion implementation .... 
bool isSubsetSum(vector<int> &a, int i, int target) {
    if(target == 0) return true ;
    if(i == 0) return (a[0] == target) ;
    bool notTake = isSubsetSum(a, i-1, target) ;
    bool take = false ;
    if(target >= a[i]) take = isSubsetSum(a, i-1, target-a[i]) ;
    return take || notTake ;
}

// Memoization implementation ... 
bool isSubsetSum(vector<int> &a, int i, int target, vector<vector<int>> &dp) {
    if(target == 0) return true ;
    if(i == 0) return (a[0] == target) ;
    if(dp[i][target] != -1) return dp[i][target] ;
    bool notTake = isSubsetSum(a, i-1, target, dp) ;
    bool take = false ;
    if(target >= a[i]) take = isSubsetSum(a, i-1, target-a[i], dp) ;

    return dp[i][target] = (take | notTake) ;
}

// Tabulation Implementation ....
bool isSubsetSumTab(vector<int> &a, int k) {
    int n = a.size() ;
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0)) ;
    for(int i=0; i<n; i++) dp[i][0] = true ;
    dp[0][a[0]] = true ;
    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) {
            bool notTake = dp[i-1][j] ;
            bool take = false ;
            if(j >= a[i]) take = dp[i-1][j-a[i]] ;
            dp[i][j] = (take | notTake) ;
        }
    }
    return dp[n-1][k] ;
}

int main()
{
    vector<int> a({2, 3, 1, 1}) ; int target = 8 ;
    int n = a.size() ;
    // vector<vector<int>> dp(n, vector<int>(target+1, -1)) ;
    // if(isSubsetSum(a, n-1, target, dp)) cout << "True" << endl ;
    // else cout << "False" << endl ;
    if(isSubsetSumTab(a, target)) cout << "True" << endl ;
    else cout << "False" << endl ;


    return 0 ;
}