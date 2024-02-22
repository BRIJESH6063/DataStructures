#include<bits/stdc++.h>
using namespace std ;

// count the number of longest increasing subsequence 
int countLIS(vector<int> arr) {
    int n = arr.size() ;
    vector<int> dp(n, 1), count(n, 1) ;
    int maxi = 0 ;
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]) {
                dp[i] = 1+dp[prev] ;
                count[i] = count[prev] ; // inherit the count if dp[i] updated..
            }
            else if(arr[prev] < arr[i] && 1+dp[prev] == dp[i])
            count[i] += count[prev] ;    // update the count .. 
        }
        maxi = max(maxi, dp[i]) ;
    }
    int nos = 0 ;
    for(int i=0; i<n; i++) {
        if(dp[i] == maxi) nos += count[i] ;
    }
    return nos ;
}

int main()
{
    vector<int> arr({1, 5, 4, 7}) ;
    cout << countLIS(arr) << endl ;

    return 0 ;
}