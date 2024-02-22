#include <bits/stdc++.h>
using namespace std;

// distance of nearest cell having 1.. 
// 1. BFS Implementation ... 

vector<vector<int>> nearest(vector<vector<int>> &grid) {
    int m = grid.size() ;
    int n = grid[0].size() ;
    vector<vector<int>> vis(m, vector<int>(n, 0)) ;
    vector<vector<int>> dist(m, vector<int>(n, 0)) ;
    queue<pair<pair<int, int>, int>> q ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1) {
                q.push({{i, j}, 0}) ;
                vis[i][j] = 1 ;
            }
            else vis[i][j] = 0 ;
        }
    }
    int dr[] = {-1, 0, 1, 0} ;
    int dc[] = {0, -1, 0, 1} ;
    while(!q.empty()) {
        int r = q.front().first.first ;
        int c = q.front().first.second ;
        int steps = q.front().second ;
        q.pop() ;
        dist[r][c] = steps ;
        for(int i=0; i<4; i++) {
            int nrow = r + dr[i] ;
            int ncol = c + dc[i] ;
            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1 ;
                q.push({{nrow, ncol}, steps+1}) ;
            }
        }
    }   
    return dist ;
} 

int main() {
    vector<vector<int>> grid({{}} ) ;
    
	
	return 0 ;
}
