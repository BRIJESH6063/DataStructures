#include<bits/stdc++.h>
using namespace std;

// dfs matrix implementation 
void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, int dr[], int dc[]) {
    vis[row][col] = 1 ;
    int m = grid.size() ;
    int n = grid[0].size() ;
    for(int i=0; i<4; i++) {
        int nr = row + dr[i] ;
        int nc = col + dc[i] ;
        if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 'O') {
            dfs(nr, nc, grid, vis, dr, dc) ;
        }
    }
}
// Surrounded regions // Replace inner O's with X'S
void surroundedRegions(vector<vector<char>> &grid) {
    int m = grid.size() ;
    int n = grid[0].size() ;
    vector<vector<int>> vis(m, vector<int>(n, 0)) ;
    int dr[] = {-1, 0, 1, 0} ;
    int dc[] = {0, -1, 0, 1} ;
    // Row wise traversal
    for(int i=0; i<m; i++) {
        if(!vis[i][0] && grid[i][0] == 'O') 
        dfs(i, 0, grid, vis, dr, dc) ;
        if(!vis[i][n-1] && grid[i][n-1] == 'O')
        dfs(i, n-1, grid, vis, dr, dc) ;
    }
    // col wise traversal
    for(int i=0; i<n; i++) {
        if(!vis[0][i] && grid[0][i] == 'O') 
        dfs(0, i, grid, vis, dr, dc) ;
        if(!vis[m-1][i] && grid[m-1][i] == 'O')
        dfs(m-1, i, grid, vis, dr, dc) ;
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j] && grid[i][j] == 'O')
            grid[i][j] = 'X' ;
        }
    }
}


int main() {
    vector<vector<char>> grid = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}};

    for(auto x : grid) {
        for(auto y : x) cout << y << "  " ;
        cout << endl ;
    }
    cout << "---------------------------------------" << endl ;
    surroundedRegions(grid) ;
    for(auto x : grid) {
        for(auto y : x) cout << y << "  " ;
        cout << endl ;
    }
	// {, {}, {}, {}}
	return 0 ;
}
