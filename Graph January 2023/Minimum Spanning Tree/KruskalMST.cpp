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


// Kruskal's Algorithm 
// Minimum Spanning Trees 
int spanningTree(int V, vector<vector<int>> adj[]) {
   vector<pair<int, pair<int, int>>> edges ;
   for(int i=0; i<V; i++) {
      for(auto it : adj[i]) {
         int adjNode = it[0] ;
         int wt = it[1] ;
         int node = i ;
         edges.push_back({wt, {node, adjNode}}) ;
      }
   }

   DisjointSet ds(V) ;
   sort(edges.begin(), edges.end()) ;
   int mswt = 0 ;
   for(auto it : edges ) {
      int wt = it.first ;
      int u = it.second.first ;
      int v = it.second.second ;
      if(ds.FindUPar(u) != ds.FindUPar(v)) {
         mswt += wt ;
         ds.unionBySize(u, v) ;
      }
   }
   return mswt ;
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

   DisjointSet ds(7) ;
   ds.unionBySize(1, 2) ;
   ds.unionBySize(2, 3) ;
   ds.unionBySize(4, 5) ;
   ds.unionBySize(6, 7) ;
   ds.unionBySize(5, 6) ;

   if(ds.FindUPar(3) == ds.FindUPar(7)) cout << "3 and 7 are under same Ultimate Parent" << endl ;
   else cout << "3 and 7 are not under same Ultimate Parent" << endl ;


   return 0;
}


