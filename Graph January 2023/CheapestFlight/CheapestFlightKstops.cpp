#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Cheapest Flight within k stops  .. 
// Dijkstras Algorithm Shortest path Modified 
// since stops are taking stepwise hence dont need priority_queue.
int cheapestFlight(int n, vector<vector<int>> &flights, int src, int dest, int k) {
    vector<pair<int, int>> adj[n] ;
    for(auto it : flights) {
      adj[it[0]].push_back({it[1], it[2]}) ;
    }
    // queue --> stops node 
    queue<pair<int, pair<int, int>>> q ;
    q.push({0, {src, 0}}) ;
    vector<int> dist(n, 1e9) ;
    dist[src] = 0 ;
    while(!q.empty()) {
      auto it = q.front() ;
      q.pop() ;
      int stop = it.first ;
      int node = it.second.first ;
      int cost = it.second.second ;
      if(stop > k) continue ;
      for(auto x : adj[node]) {
         int adjNode = x.first ;
         int edw = x.second ;
         if(cost + edw < dist[adjNode] && stop <= k) {
            dist[adjNode] = cost + edw ;
            q.push({stop+1, {adjNode, cost+edw}}) ;
         }
      }
    }
    if(dist[dest] == 1e9) return -1 ;
    else return dist[dest] ;
}

int main() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL) ;

   // #ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin) ;
   // freopen("output.txt", "w", stdout) ;
   // #endif 

   cout << "Hello World!.." << endl ;

   return 0;
}


