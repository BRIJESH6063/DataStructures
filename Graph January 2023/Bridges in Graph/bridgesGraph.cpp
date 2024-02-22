#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Bridges in Graph 
// Edges which can divide graph into two components/subGroup on it's removal.
// Critical connections in Graph 

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[],
   int low[], vector<vector<int>> &bridges, int timer) {
   vis[node] = 1 ;
   tin[node] = low[node] = timer ;
   timer ++ ;
   for(auto it : adj[node]) {
      if(it == parent) continue ;
      if(vis[it] == 0) {
         dfs(it, node, vis, adj, tin, low, bridges, timer) ;
         low[node] = min(low[node], low[it]) ;
         if(low[it] > tin[node]) {
            bridges.push_back({it, node}) ;
         }
      }
      else low[node] = min(low[node], low[it]) ;
   }
}

vector<vector<int>> criticalConnection(int n, vector<vector<int>> &connections) {
   vector<int> adj[n] ;
   for(auto it : connections) {
      adj[it[0]].push_back(it[1]) ;
      adj[it[1]].push_back(it[0]) ;
   }

   vector<int> vis(n, 0) ;
   int tin[n] ;
   int low[n] ;
   int timer = 1 ;
   vector<vector<int>> bridges ;
   dfs(0, -1, vis, adj, tin, low, bridges, timer) ;
   return bridges ;
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


