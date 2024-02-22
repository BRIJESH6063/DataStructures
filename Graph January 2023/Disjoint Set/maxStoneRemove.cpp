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

// G53. Most stones removed with same Row and Column 
// A stone can be removed if it shrares same row or same column that has not been removed 
// code Implementation ...
int maxRemove(vector<vector<int>> &stones, int n) {
   int maxRow = 0 ;
   int maxCol = 0 ;
   for(auto it : stones ) {
      maxRow = max(maxRow, it[0]) ;
      maxCol = max(maxCol, it[1]) ;
   }

   DisjointSet ds(maxRow+maxCol+1) ;
   unordered_map<int, int> stoneNodes ;
   for(auto it : stones) {
      int nodeRow = it[0] ;
      int nodeCol = it[1] + maxRow + 1 ;
      ds.unionBySize(nodeRow, nodeCol) ;
      stoneNodes[nodeRow] = 1 ;
      stoneNodes[nodeCol] = 1 ;
   }

   int count = 0 ;
   for(auto it : stoneNodes) {
      if(ds.FindUPar(it.first) == it.first) count++ ;
   }
   return n-count ;
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


