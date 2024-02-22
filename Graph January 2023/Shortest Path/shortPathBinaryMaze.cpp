#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Shortest distance in binary maze .. 
// Dijkstras Algorithm Shortest path 
// priority_queue<dist, row, col> NOT REQUIRED.., 4 directions <--, | , -->
int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dest) {
    if(grid[src.first][src.second] == 0) return -1 ;
    if(src.first == dest.first && src.second == dest.second) return 0 ;
    
    int dr[] = {-1, 0, 1, 0} ;
    int dc[] = {0, -1, 0, 1} ;
    queue<pair<int, pair<int, int>>> q ;
    // priority queue not required since weight not assingned.
    int m = grid.size() ; int n = grid[0].size() ;
    vector<vector<int>> dist(m, vector<int>(n, 1e9)) ;
    q.push({0, {src.first, src.second}}) ;
    dist[src.first][src.second] = 0 ;
    while(!q.empty()) {
        auto it = q.front() ;
        q.pop() ;
        int dis = it.first ;
        int r = it.second.first ;
        int c = it.second.second ;
        for(int i=0; i<4; i++) {
            int nr = r + dr[i] ;
            int nc = c + dc[i] ;
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]) {
                dist[nr][nc] = 1 + dis ;
                if(nr == dest.first && nc == dest.second ) return 1+dis ;
                q.push({dis+1, {nr, nc}}) ;
            }
        }
    }
    return -1 ;
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(NULL) ;

//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin) ;
//    freopen("output.txt", "w", stdout) ;
//    #endif 

   cout << "Hello World!.." << endl ;

   return 0;
}


