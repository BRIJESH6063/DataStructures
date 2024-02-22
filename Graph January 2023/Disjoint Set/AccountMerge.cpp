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

// Merging Details | Account Merge | DSU ( Disjoint Set Union )
vector<vector<string>> mergeDaetails(vector<vector<string>> &details) {
   int n = details.size() ;
   DisjointSet ds(n) ;
   unordered_map<string, int> mapMailNode ;
   for(int i=0; i<n; i++) {
      for(int j=1; j<details[i].size(); j++) {
         string mail = details[i][j] ;
         if(mapMailNode.find(mail) == mapMailNode.end()) 
            mapMailNode[mail] = i ;
         else ds.unionBySize(i, mapMailNode[mail] ) ;
      }
   }
   vector<string> mergeMail[n] ;
   for(auto it : mapMailNode) {
      string mail = it.first ;
      int node = ds.FindUPar(it.second) ;
      mergeMail[node].push_back(mail) ;
   }

   vector<vector<string>> ans ;
   for(int i=0; i<n; i++) {
      if(mergeMail[i].size() == 0) continue ;
      sort(mergeMail[i].begin(), mergeMail[i].end()) ;
      vector<string> temp ;
      temp.push_back(details[i][0]) ;
      for(auto it : mergeMail[i]) {
         temp.push_back(it) ;
      }
      ans.push_back(temp) ;
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


