#include <bits/stdc++.h>
using namespace std;

// recursive implementation ..
int minPathSum(vector<vector<int>> &grid, int i, int j)
{
    if (i == 0 && j == 0) return grid[i][j];
    if (i < 0 || j < 0) return 1e9 ;
    int up = grid[i][j] + minPathSum(grid, i-1, j);
    int left =  grid[i][j]  + minPathSum(grid, i, j-1) ;
    
    return min(up, left) ;
}

// memeoization implementation .......
int minPathSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0) return grid[i][j];
    if (i < 0 || j < 0) return 1e9 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int up = grid[i][j] + minPathSum(grid, i-1, j, dp);
    int left =  grid[i][j]  + minPathSum(grid, i, j-1, dp) ;
    return dp[i][j] = min(up, left) ;
}

// Tabulation implementation .......
int minPathSumT(vector<vector<int>> &grid, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0)) ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j] ;
            else {
                int up = grid[i][j] ; 
                if(i > 0) up += dp[i-1][j] ;
                else up += 1e9 ;

                int left = grid[i][j] ; 
                if(j > 0) left += dp[i][j-1] ;
                else left += 1e9 ;

                dp[i][j] = min(left, up) ;
            }
        }
    }

    return dp[m-1][n-1] ;
}

int main()
{
    vector<vector<int>> grid({{1, 3, 1},
                              {1, 5, 1},
                              {4, 2, 1}}) ;
    int i = grid.size() ; int j = grid[0].size() ;
    // cout << minPathSum(grid, i-1, j-1) << endl ;
    // vector<vector<int>> dp(i, vector<int>(j, -1)) ;
    // cout << minPathSum(grid, i-1, j-1, dp) << endl ;
    cout << minPathSumT(grid, i, j) << endl ;
    
    return 0;
}