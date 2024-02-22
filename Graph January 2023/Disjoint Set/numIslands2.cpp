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
   private : vector<int> rank, parent, size ;
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

bool isValid(int nr, int nc, int n, int m) {
   return (nr >= 0 && nr < n && nc >= 0 && nc < m) ;
}

// Number of Islands | Online Queries | DSU ( Disjoint Set Union )
// number of Islands after all the querries.
// Code Implementation ..
vector<int> numIslands(int n, int m, vector<vector<int>> &operations) {
   DisjointSet ds(n*m) ;
   int vis[n][m] = {0} ;
   int count = 0 ;
   vector<int> ans ;
   for(auto it : operations) {
      int row = it[0] ;
      int col = it[1] ;
      if(vis[row][col] == 1) {
         ans.push_back(count) ;
         continue ;
      }
      vis[row][col] = 1 ;
      count++ ;
      int dr[] = {-1, 0, 1, 0} ;
      int dc[] = {0, -1, 0, 1} ;
      for(int i=0; i<4; i++) {
         int nr = row + dr[i] ;
         int nc = col + dc[i] ;
         if(isValid(nr, nc, n, m)) {
            if(vis[nr][nc] == 1) {
               int nodeNo = row*m + col ;
               int adjNode = nr*m + nc ;
               if(ds.FindUPar(nodeNo) != ds.FindUPar(adjNode)) {
                  count-- ;
                  ds.unionBySize(nodeNo, adjNode) ;
               }
            }
         }
      }
      ans.push_back(count) ;
   }
   return ans ;
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


