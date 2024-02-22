#include<bits/stdc++.h>
using namespace std ;

// recursive implementation .... 
int uPathObst(vector<vector<int>> &maze, int i, int j) {
    if(i >= 0 && j >= 0 && maze[i][j] == -1) return 0 ;
    if(i == 0 && j == 0) return 1 ; 
    if(i < 0 || j < 0) return 0 ;
    int up = 0 ; int left = 0 ;
        if(i > 0) up = uPathObst(maze, i-1, j) ;
        if(j > 0) left = uPathObst(maze, i, j-1) ;
        return up + left ;
}

// memoization implementation .... 
int uPathObst(vector<vector<int>> &maze, vector<vector<int>> &dp, int i, int j) {
    if(i >= 0 && j >= 0 && maze[i][j] == -1) return 0 ;
    if(i == 0 && j == 0) return 1 ; 
    if(i < 0 || j < 0) return 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    int up = 0 ; int left = 0 ;
        if(i > 0) up = uPathObst(maze, dp, i-1, j) ;
        if(j > 0) left = uPathObst(maze, dp, i, j-1) ;
        return dp[i][j] = up + left ;
}

// Tabulation Implementation ... 
int uPathOptT(vector<vector<int>> &maze, int m, int n) {
    int dp[m][n] = {0} ; 
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(maze[i][j] == -1) {
                dp[i][j] = 0 ; continue ;
            }
            if(i ==0 && j == 0) dp[i][j] = 1 ;
            else {
                int up = 0 ; int left = 0 ;
                if(i > 0) up = dp[i-1][j] ;
                if(j > 0) left = dp[i][j-1] ;
                dp[i][j] = up + left  ;
            }
        }
    }
    return dp[m-1][n-1] ;
}

// space optimisation .. 
int uPathOptS(vector<vector<int>> &maze, int m, int n) {
    vector<int> prev(n, 0) ;
    for(int i=0; i<m; i++) {
        vector<int> curr(n, 0) ;
        for(int j=0; j<n; j++) {
            if(maze[i][j] == -1) {
                curr[j] = 0 ; continue ;
            }
            if(i ==0 && j == 0) curr[j] = 1 ;
            else {
                int up = 0 ; int left = 0 ;
                if(i > 0) up = prev[j] ;
                if(j > 0) left = curr[j-1] ;
                curr[j] = up + left  ;
            }
        }
        prev = curr ;
    }
    
    return prev[n-1] ;
}

int main()
{
    vector<vector<int>> maze({{0, 0, 0},
                              {0, -1, 0},
                              {0, 0, 0}}) ;
    int m = maze.size() ; int n = maze[0].size() ;
    // cout << uPathObst(maze, m-1, n-1) << endl ;
    // int m ; int n ; cin >> m >> n ;
    // vector<vector<int>> maze ; int x ;
    // for(int i=0; i<m; i++) {
    //     vector<int> temp ;
    //     for(int j=0; j<n; j++) {
    //         cin >> x ; temp.push_back(x) ;
    //     }
    //     maze.push_back(temp) ;
    // }
    // vector<vector<int>> dp(m, vector<int>(n, -1)) ;
    // cout << uPathObst(maze, dp, m-1, n-1) << endl ;
    // cout << uPathOptT(maze, m, n) << endl ;
    cout << uPathOptS(maze, m, n) << endl ;
    return 0 ;
}