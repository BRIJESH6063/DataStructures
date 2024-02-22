#include<bits/stdc++.h>
using namespace std ;

// Number of Enclaves .. // Multi Source BFS 
// find number of land cells in grid from which we cannot walk off the boundary 

int numEnclaves1(vector<vector<int>> &grid) {
    int m = grid.size() ;
    int n = grid[0].size() ;
    queue<pair<int, int >> q ;
    vector<vector<int>> vis(m, vector<int>(n, 0)) ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || j == 0 || i == m-1 || j == n-1 ) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    q.push({i, j}) ;
                    vis[i][j] = 1 ;
                }
            }
        }
    }

    int dr[] = {-1, 0, 1, 0} ;
    int dc[] = {0, -1, 0, 1} ;
    while(!q.empty()) {
        int r = q.front().first ;
        int c = q.front().second ;
        q.pop() ;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i] ;
            int nc = c + dc[i] ;
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                q.push({nr, nc}) ;
                vis[nr][nc] = 1 ;
            }
        }
    }
    int count = 0 ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) 
            count++ ;
        }
    }

    return count ;
}

int main() 
{



    return 0 ; 
}