#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Path with minimum effort  .. 
// Dijkstras Algorithm Shortest path 
// priority_queue<effort, row, col> , 4 directions <--, | , -->
int minEffort(vector<vector<int>> &heights) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
    greater<pair<int, pair<int, int>>>> pq ;
    int m = heights.size() ;
    int n = heights[0].size() ;
    vector<vector<int>> dist(m, vector<int>(n, 1e9)) ;
    dist[0][0] = 1 ;
    pq.push({0, {0, 0}}) ;
    int dr[] = {-1, 0, 1, 0} ;
    int dc[] = {0, -1, 0, 1} ;
    while(!pq.empty()) {
      auto it = pq.top() ;
      pq.pop() ;
      int diff = it.first ;
      int r = it.second.first ;
      int c = it.second.second ;
      if(r == m-1 && c == n-1) return diff ;
      for(int i=0; i<4; i++) {
         int nr = r + dr[i] ;
         int nc = c + dc[i] ;
         if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
            int newEffort = max(abs(heights[r][c] - heights[nr][nc]), diff) ;
            if(newEffort < dist[nr][nc]) {
               dist[nr][nc] = newEffort ;
               pq.push({newEffort, {nr, nc}}) ;
            }
         }
      }
   }
   return 0 ; // unreachable 
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL) ;

//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin) ;
//    freopen("output.txt", "w", stdout) ;
//    #endif 

   cout << "Hello World!.." << endl ;

   return 0;
}


