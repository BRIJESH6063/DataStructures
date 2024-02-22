#include<bits/stdc++.h>
using namespace std ;

// Tabulation Implementation Subset Sum 2 k ....
bool isSubsetSumTab(vector<int> &a, int k) {
    int n = a.size() ;
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
    return dp[n-1][k] ;
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

bool canPartition(vector<int> &a) {
    int n = a.size() ; int sum = 0 ;
    for(int i=0; i<n; i++) sum += a[i] ;
    if(sum%2) return false ;
    else return isSubsetSumTab(a, sum/2) ;
}

int main() 
{
    vector<int> a({1,5,11,5}) ;
    // int t ; cin >> t ;
    // while(t--) {
    //     int n ; cin >> n ; int x ; vector<int> a ;
    //     for(int i=0; i<n; i++) {
    //         cin >> x ; a.push_back(x) ;
    //     }
    //     if(canPartition(a)) cout << "True" << endl ;
    //     else cout << "False" << endl ;
    // }
    if(canPartition(a)) cout << "True" << endl ;
    else cout << "False" << endl ;
    

    return 0 ;
}

