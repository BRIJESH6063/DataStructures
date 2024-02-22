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


// Number of Operations to make network connected ..
// Disjoint Set.
// Code Implementation ..

// You are allowed to remove one edge from anywhere and add the edge between any 
// two vertices in one operation. Number of such operations required ? .. 
// Solution Approaches like --> number of edges required to connect the Disjoint union components(let say n)
// edges required = n-1 ;

int solve(int n, vector<vector<int>> &edges) {
   DisjointSet ds(n) ;
   int countExtras = 0 ;
   for(auto it : edges) {
      int u = it[0] ;
      int v = it[1] ;
      if(ds.FindUPar(u) == ds.FindUPar(v) ) countExtras ++ ;
      else ds.unionBySize(u, v) ;
   }
   int countC = 0 ;
   for(int i=0; i<n; i++) {
      if(ds.FindUPar(i) == i ) countC++ ;
   }

   int ans = countC -1 ;
   if(countExtras >= ans) return ans ;
   else return -1 ;
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
   ds.unionByRank(1, 2) ;
   ds.unionByRank(2, 3) ;
   ds.unionByRank(4, 5) ;
   ds.unionByRank(6, 7) ;
   ds.unionByRank(5, 6) ;

   //    if(ds.FindUPar(3) == ds.FindUPar(7)) cout << "3 and 7 are under same Ultimate Parent" << endl ;
   //    else cout << "3 and 7 are not under same Ultimate Parent" << endl ;


   return 0;
}


