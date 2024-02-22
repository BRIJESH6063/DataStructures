#include<bits/stdc++.h>
using namespace std ;

// matrix chain multiplication ....
// recurrence implementation ..
int matrixChain(vector<int> &arr, int i, int j) {
    if(i == j) return 0 ;
    int mini = 1e9 ;
    for(int k=i; k<j; k++) {
        int steps = (arr[i-1]*arr[k]*arr[j]) + 
        matrixChain(arr, i, k) + matrixChain(arr, k+1, j) ;
        mini = min(mini, steps) ;
    }
    return mini ;
}

// memoization implementation .... 
int matrixChain(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if(i == j) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int mini = 1e9 ;
    for(int k=i; k<j; k++) {
        int steps = (arr[i-1]*arr[k]*arr[j]) + 
        matrixChain(arr, i, k, dp) + matrixChain(arr, k+1, j, dp) ;
        mini = min(mini, steps) ;
    }
    return dp[i][j] = mini ;
}

// Tabulation Implementation ... 
int matrixChainT(vector<int> &arr) {
    int n = arr.size() ;
    vector<vector<int>> dp(n, vector<int>(n, 0)) ;
    for(int i=0; i<n; i++) dp[i][i] = 0 ;
    for(int i=n-1; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            int mini = 1e9+7 ;
            for(int k=i; k<j; k++) {
                int steps = (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j] ;
                mini = min(mini, steps) ;
            }
            dp[i][j] = mini ;
        }
    }
    return dp[1][n-1] ;
}

int main()
{
    vector<int> arr({10, 20, 30}) ;
    int n = arr.size() ;
    // vector<vector<int>> dp(n, vector<int>(n, -1)) ;
    cout << matrixChainT(arr) << endl ;

    return 0 ;
}