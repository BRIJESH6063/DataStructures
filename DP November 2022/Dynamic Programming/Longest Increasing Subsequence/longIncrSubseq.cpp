#include<bits/stdc++.h>
using namespace std ;

// recursive implementation ... 
int longIncrSubseq(vector<int> &arr, int i, int prevI) {
    int n = arr.size() ;
    if(i == n) return 0 ;
    int len = 0 + longIncrSubseq(arr, i+1, prevI) ;
    if(prevI == -1 || arr[i] > arr[prevI]) 
    len = max(len, 1 + longIncrSubseq(arr, i+1, i)) ;
    return len ;
}

// memoization implementation ...
int longIncrSubseq(vector<int> &arr, int i, int prevI, vector<vector<int>> &dp) {
    int n = arr.size() ;
    if(i == n) return 0 ;
    if(dp[i][prevI+1] != -1) return dp[i][prevI+1] ; 
    int len = 0 + longIncrSubseq(arr, i+1, prevI, dp) ;
    if(prevI == -1 || arr[i] > arr[prevI]) 
    len = max(len, 1 + longIncrSubseq(arr, i+1, i, dp)) ;
    return dp[i][prevI+1] = len ;
}

// Tabulation Implementation ...
int longIncrSubseq(vector<int> &arr) {
    int n = arr.size() ;
    vector<vector<int>> dp(n+1, vector<int>(n+2, 0)) ;
    for(int i=n-1; i>=0; i--) {
        for(int j=i-1; j>=-1; j--) {
            dp[i][j+1] = 0 + dp[i+1][j+1] ;
            if(j == -1 || arr[i] > arr[j]) dp[i][j+1] = max(dp[i][j+1], 1 + dp[i+1][i+1]) ;
        }
    }
    return dp[0][-1+1] ;
}

// space optimisation .. 
int longIncrSubseqS(vector<int> &arr) {
    int n = arr.size() ; int maxi = 0 ;
    vector<int> dp(n, 1) ;
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<i; prev++) {
            if(arr[prev] < arr[i]) dp[i] = max(1+dp[prev], dp[i]) ;
        }
        maxi = max(maxi, dp[i]) ;
    }
    return maxi ;
}

// LIS using Binary Search ... 
// to put new comming element at correct position
int longIncrSubseqBS(vector<int> &arr) {
    int n = arr.size() ; 
    vector<int> temp ;
    temp.push_back(arr[0]) ;
    for(int i=1; i<n; i++) {
        if(arr[i] > temp.back()) temp.push_back(arr[i]) ;
        else {
            auto ind = (lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin()) ;
            temp[ind] = arr[ind] ;
        }
    }
    return temp.size() ;
}


int main()
{
    vector<int> arr({1, 2, 2}) ;
    int n = arr.size() ;

    // for strictly increasing .... 
    unordered_set<int> s ;
    for(int i=0; i<n; i++) s.insert(arr[i]) ;
    vector<int> array ;
    for(auto x : s) array.push_back(x) ;


    // vector<vector<int>> dp(n, vector<int>(n+1, -1)) ;
    // cout << longIncrSubseq(arr, 0, -1, dp) << endl ;
    cout << longIncrSubseqBS(array) << endl ;
    return 0 ;
}