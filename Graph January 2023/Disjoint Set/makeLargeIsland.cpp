#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Disjoint Set| Union By Size | Path Compression. 
// Changing or Variable Graph 
// Union(u, v) 
// Find the Ultimate Parent of u and v
// find rank of pu and pv
// Connect smaller rank to larger rank always.. 
// Disjoint set by Rank 
// Code Implementation of DisjointSet
class DisjointSet {
    public : vector<int> rank, parent, size ;
    public :
        DisjointSet(int n) {
            rank.resize(n+1, 0) ;
            parent.resize(n+1)  ;
            size.resize(n+1) ;
            for(int i=0; i<=n; i++) {
                parent[i] = i ;
                size[i] = 1 ;
            }
      }
      int FindUPar(int node) {
            if(node == parent[node]) return node ;
            return parent[node] = FindUPar(parent[node]) ;
      }
         
      // Union by size 
      void unionBySize(int u, int v) {
            int ult_pu = FindUPar(u) ;
            int ult_pv = FindUPar(v) ;
            if(ult_pu == ult_pv) return ; 
            if(size[ult_pu] < size[ult_pv]) {
                parent[ult_pu] = ult_pv ;
                size[ult_pv] += size[ult_pu] ;
            }
            else {
                parent[ult_pv] = ult_pu ;
                size[ult_pu] += size[ult_pv] ;
            }
      }

      void unionByRank(int u, int v) {
        int ult_pu = FindUPar(u) ;
        int ult_pv = FindUPar(v) ;
        if(ult_pu == ult_pv) return ; 
        if(rank[ult_pu] < rank[ult_pv]) {
            parent[ult_pu] = ult_pv ;
        }
        else if(rank[ult_pv] < rank[ult_pu]) {
            parent[ult_pv] = ult_pu ;
        }
        else {
            parent[ult_pv] = ult_pu ;
            rank[ult_pu] ++ ;
        }
      }
} ;

bool isValid(int nr, int nc, int n) {
   return (nr >= 0 && nr < n && nc >= 0 && nc < n) ;
}


// Making a large Island | Making a large connected Group | DSU (Disjoint Set Union)
int maxConnections(vector<vector<int>> &grid) {
   int n = grid.size() ;
   DisjointSet ds(n*n) ;
   for(int row=0; row<n; row++) {
      for(int col=0; col<n; col++) {
         if(grid[row][col] == 0) continue ;
         int dr[] = {-1, 0, 1, 0} ;
         int dc[] = {0, -1, 0, 1} ;
         for(int i=0; i<4; i++) {
            int nr = row + dr[i] ;
            int nc = col + dc[i] ;
            if(isValid(nr, nc, n) && grid[nr][nc] == 1) {
               int nodeNo = row*n + col ;
               int adjNodeNo = nr*n + nc ;
               ds.unionBySize(nodeNo, adjNodeNo) ;
            }
         }
      }
   }

   int mx = 0 ;
   for(int row=0; row<n; row++) {
      for(int col=0; col<n; col++) {
         if(grid[row][col] == 1) continue ;
         int dr[] = {-1, 0, 1, 0} ;
         int dc[] = {0, -1, 0, 1} ;
         set<int> components ;
         for(int ind=0; ind<4; ind++) {
            int nr = row + dr[ind] ;
            int nc = col + dc[ind] ;
            if(isValid(nr, nc, n) && grid[nr][nc] == 1) {
               components.insert(ds.FindUPar(nr*n+nc)) ;
            }
         }
         int sizeTotal = 0 ;
         for(auto it : components) {
            sizeTotal += ds.size[it] ;
         }
         mx = max(mx, sizeTotal+1) ;
      }
   }
   for(int cellNo = 0 ; cellNo <(n*n) ; cellNo++) {
      mx = max(mx, ds.size[ds.FindUPar(cellNo)]) ;
   }
   return mx ;
}

void sublimeInit() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL) ;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin) ;
   freopen("output.txt", "w", stdout) ;
   #endif 
}

int main() {
   // sublimeInit() ;
   cout << "Hello World!.." << endl ;

   
   return 0;
}


