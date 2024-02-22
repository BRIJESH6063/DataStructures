#include<bits/stdc++.h>
using namespace std ;

// Recursive Implementation ... 
int minTrianglePath(vector<vector<int>> &Triangle, int i=0, int j=0) {
    int n = Triangle.size() ;
    if(i == n-1) return Triangle[i][j] ;

    int down = Triangle[i][j] + minTrianglePath(Triangle, i+1, j) ;
    int diag = Triangle[i][j] + minTrianglePath(Triangle, i+1, j+1) ;

    return min(down, diag) ;
}

// Memoization Implementation ... 
int minTrianglePath(vector<vector<int>> &Triangle, vector<vector<int>> &dp, int i=0, int j=0) {
    int n = Triangle.size() ;
    if(i == n-1) return Triangle[i][j] ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int down = Triangle[i][j] + minTrianglePath(Triangle, dp, i+1, j) ;
    int diag = Triangle[i][j] + minTrianglePath(Triangle, dp, i+1, j+1) ;

    return dp[i][j] = min(down, diag) ;
}

// Tabulation Implementation ... 
int minTPathTab(vector<vector<int>> &Triangle) {
    int n = Triangle.size() ; 
    vector<vector<int>> dp(n, vector<int>(n,0)) ;
    for(int i=0; i<n; i++) dp[n-1][i] = Triangle[n-1][i] ;
    for(int i=n-2; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int down = Triangle[i][j] + dp[i+1][j] ;
            int diag = Triangle[i][j] + dp[i+1][j+1] ;


            dp[i][j] = min(down, diag) ;
        }
    }

    return dp[0][0] ;
}

// space optimisation ... 
int minTPathSO(vector<vector<int>> &Triangle) {
    int n = Triangle.size() ; 
    vector<int> temp(Triangle[n-1]) ;
    for(int i=n-2; i>=0; i--) {
        vector<int> curr(n, 0) ;
        for(int j=i; j>=0; j--) {
            int down = Triangle[i][j] + temp[j] ;
            int diag = Triangle[i][j] + temp[j+1] ;
            curr[j] = min(down, diag) ;
        }
        temp = curr ;
    }
    return temp[0] ; 
}

int main()
{
    vector<vector<int>> Triangle({{1},
                                  {2, 3},
                                  {3, 6, 7},
                                  {8, 1, 6, 10}}) ;
    // cout << minTrianglePath(Triangle) << endl ;
    // int n = Triangle[m-1].size() ;
    // int m = Triangle.size() ; 
    // vector<vector<int>> dp(m, vector<int>(m, -1)) ;

    // cout << minTrianglePath(Triangle, dp) << endl ;
    // cout << minTPathTab(Triangle) << endl ;
    cout << minTPathSO(Triangle) << endl ;

    return 0 ;
}