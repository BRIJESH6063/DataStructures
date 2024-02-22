#include<bits/stdc++.h>
using namespace std ;

// print Longest increasing subsequence .. 
void printLIS(vector<int> &arr) {
    int n= arr.size() ; int maxi = 0 ;
    vector<int> dp(n, 1), hash(n, 0) ;
    int lastIndex = 0 ;
    for(int i=0; i<n; i++) {
        hash[i] = i ;
        for(int prev=0; prev<i; prev++) {
            if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev] ;
                hash[i] = prev ;
            }
        }
        if(dp[i] > maxi) {
            maxi = maxi = dp[i] ;
            lastIndex = i ;
        }
    }
    vector<int> temp ;
    temp.push_back(arr[lastIndex]) ;
    while(hash[lastIndex]!= lastIndex) {
        lastIndex = hash[lastIndex] ;
        temp.push_back(arr[lastIndex]) ;
    }
    reverse(temp.begin(), temp.end()) ;
    for(auto x : temp) cout << x << "  " ;
    cout << endl ;
}

int main()
{
    vector<int> arr({5, 4, 11, 1, 16, 8}) ;
    // int n = arr.size() ;
    // vector<vector<int>> dp(n, vector<int>(n+1, -1)) ;
    // cout << longIncrSubseq(arr, 0, -1, dp) << endl ;
    printLIS(arr)  ;
    return 0 ;
}