#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Minimum Spanning Tree ( MST )
// Helpful Algorithms for MST  
// 1. Prims Algorithm
int spanningTrees(int V, vector<vector<int>> adj[]) {
   // vector<vector<int>> adj[] = u--->({v1, wt1}, {v2, wt2}) and so on 
   priority_queue<pair<int, int>, vector<pair<int, int>>,
   greater<pair<int, int>>> pq ;
   vector<int> vis(V, 0) ;
   pq.push({0, 0}) ;
   int sum = 0 ;
   while(! pq.empty()) {
    auto it = pq.top() ;
    pq.pop() ;
    int node = it.second ;
    int wt = it.first ;
    if(vis[node] == 1) continue ;
    vis[node] = 1 ;
    sum += wt ;
    for(auto x : adj[node]) {
       int adjNode = x[0] ;
       int edw = x[1] ;
       if(! vis[adjNode]) {
          pq.push({ edw, adjNode }) ;
       }
    }
   }
   return sum ;
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


