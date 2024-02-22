#include <bits/stdc++.h>
using namespace std;

// BFS implementation ...
void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid) {
    int m = grid.size() ;
    int n = grid[0].size() ;
    vis[i][j] = 1 ;
    queue<pair<int, int>> q ;
    q.push({i, j}) ;
    while(!q.empty()) {
        int row = q.front().first ;
        int col = q.front().second ;
        q.pop() ;
        for(int delrow=-1; delrow<=1; delrow++) {
            for(int delcol=-1; delcol<=1; delcol++) {
                int nrow = row + delrow ;
                int ncol = col + delcol ;
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow, ncol}) ;
                }
            }
        }
    }
}

// Count Provinces...
int numProvinces(vector<vector<int>> grid, int V) {
    int m = grid.size() ;
    int n = grid[0].size() ;
    vector<vector<int>> vis(m, vector<int>(n, 0)) ;
    int count = 0 ;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!vis[i][j] && grid[i][j] == 1) {
                count ++ ; bfs(i, j, vis, grid) ;
            }
        }
    }
    
    return count ;
}

int main() {
    vector<vector<int>> matrix({ {1, 0, 1},
                                 {0, 1, 0},
                                 {1, 0, 1} }) ;
    int V = matrix.size() ;
    cout << numProvinces(matrix, V) << endl ;
	
	return 0 ;
}
