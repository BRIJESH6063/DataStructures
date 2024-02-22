#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// BellmanFord Algorithm --> 
// Failure of dijkstra for negative edgeWeight. 
// Convert Undirected Graph into Directed if not already. 
// Relax all the edges n-1 times with the relaxing method 
// every node can be approached from source node in at max n-1(n(edges)) iterations.
vector<int> BellManFord(int V, vector<vector<int>> &edges, int S) {
   vector<int> dist(V, 1e9) ;
   dist[S] = 0 ;
   for(int i=0; i<V; i++) {
      for(auto it : edges ) {
         int u = it[0] ;
         int v = it[1] ;
         int wt = it[2] ;
         if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            dist[v] = dist[u] + wt ;
         }
      }
   }
   for(auto it : edges ) {
      int u = it[0] ;
      int v = it[1] ;
      int wt = it[2] ;
      if(dist[u] != 1e9 && dist[u] + wt < dist[v]) return {-1} ;
   }

   return dist ;
}


void sublimeInit() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL) ;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin) ;
   freopen("output.txt", "w", stdout) ;
   #endif 
}

int main() {
//    sublimeInit() ;
   cout << "Hello World!.." << endl ;

   return 0;
}


