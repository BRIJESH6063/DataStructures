#include<bits/stdc++.h>
using namespace std;

// Required DFS implementation ....
void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0) {
    vis[r][c] = 1 ;
    vec.push_back({r-row0, c-col0}) ;
    int m = grid.size() ;
    int n = grid[0].size()  ;
    int dr[] = {-1, 0, 1, 0 } ;
    int dc[] = {0, -1, 0, 1 } ;
    for(int i=0; i<4; i++) {
        int nr = r + dr[i] ;
        int nc = c + dc[i] ;
        if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]){
            dfs(nr, nc, grid, vis, vec, row0, col0) ;
        }
    }
    
}

// Number of distinct Island Solving function 
// Islands that dont look alike 
int countDistinctIslands(vector<vector<int>> &grid) {
    int m = grid.size() ;
    int n = grid[0].size() ;
    vector<vector<int>> vis(m, vector<int>(n, 0)) ;
    set<vector<pair<int, int>>> st ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                vector<pair<int, int>> vec ;
                dfs(i, j, grid, vis, vec, i, j) ;
                st.insert(vec) ;
            }
        }
    }  
    return st.size() ;
}

int main() {
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}} ;
    cout << countDistinctIslands(grid) << endl ;
    
	return 0 ;
}
