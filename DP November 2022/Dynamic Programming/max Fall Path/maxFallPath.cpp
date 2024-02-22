// multiple starting and ending points in dp
#include<bits/stdc++.h>
using namespace std ;

// Recursive Implementation ....
int maxFPath(vector<vector<int>> &grid, int i, int j) {
    int n = grid.size() ; int m = grid[0].size() ;
    if(j < 0 || j >= m) return -1e8 ;
    if(i == 0) return grid[0][j] ;
    
    int strght = grid[i][j] + maxFPath(grid, i-1, j) ;
    int left = grid[i][j]   + maxFPath(grid, i-1, j-1) ;
    int right = grid[i][j]  + maxFPath(grid, i-1, j+1) ;
    
    return max(strght, max(left, right)) ;
}

// Memoization implementation .... 
int maxFPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    int n = grid.size() ; int m = grid[0].size() ;
    if(j < 0 || j >= m) return -1e8 ;
    if(i == 0) return grid[0][j] ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int strght = grid[i][j] + maxFPath(grid, i-1, j) ;
    int left = grid[i][j]   + maxFPath(grid, i-1, j-1) ;
    int right = grid[i][j]  + maxFPath(grid, i-1, j+1) ;
    
    return dp[i][j] = max(strght, max(left, right)) ;
}

// Tabulation Implementation ... 
int maxFPathTab(vector<vector<int>> &grid) {
    int n = grid.size() ; int m = grid[0].size() ;
    vector<vector<int>> dp(n, vector<int>(m, 0)) ;
    for(int j=0; j<m; j++) dp[0][j] = grid[0][j] ;
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int v = INT_MIN ; int l = INT_MIN ; int r = INT_MIN ;
            v = grid[i][j] + dp[i-1][j] ;
            if(j > 0) l = grid[i][j] + dp[i-1][j-1] ;
            if(j < m-1) r = grid[i][j] + dp[i-1][j+1] ;

            dp[i][j] = max(v, max(l, r)) ;
        }
    }
    int maxi = dp[n-1][0] ;
    for(int j=0; j<m; j++) maxi = max(maxi, dp[n-1][j]) ;
    return maxi ;
}

int main() 
{
    vector<vector<int>> grid({{1, 2, 10, 4 },
                              {100, 3, 2, 1},
                              {1, 1, 20, 2 },
                              {1, 1, 2, 1  }}) ;
    int n = grid.size() ; int m = grid[0].size() ; int maxi = -1e8 ;
    // vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    // for(int j=0; j<m; j++) {
    //     maxi = max(maxi, maxFPath(grid, n-1, j, dp)) ;
    // }
    cout << maxFPathTab(grid) << endl ;
    return 0 ;
}

