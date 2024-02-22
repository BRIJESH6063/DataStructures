#include<bits/stdc++.h>
using namespace std ;

// Dijkstras Algorithm Stack Implementation 
// Optimising the code by dekleting the already existing path with greater weight ..
// Optimising the Time Complexity ...
// Once updated weight has already given min weight to nodes to reach them
// the revisiting those nodes will only check with greater wt than previous hence USELESS, DELETE ALREADY UPDATED ONES.

// Print the Shortest Path .. 

vector<int> shortestPath1(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n+1] ;
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]}) ;
        adj[it[1]].push_back({it[0], it[2]}) ;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;
    vector<int> dist(n+1, 1e9), parent(n+1) ;
    for(int i=1; i<=n; i++) parent[i] = i ;
    dist[1] = 0 ;
    pq.push({0, 1}) ; // start node 1 with weight 0 ;
    while(! pq.empty()) {
        auto it = pq.top() ;
        int node = it.second ;
        int dis = it.first ;
        pq.pop() ;
        
        for(auto x : adj[node]) {
            int adjNode = x.first ;
            int edw = x.second ;
            if(dis + edw < dist[adjNode]) {
                dist[adjNode] = dis + edw ;
                pq.push({dis + edw, adjNode}) ;
                parent[adjNode] = node ;
            }
        }
    }
    
    if(dist[n] == 1e9) return {-1} ;
    vector<int> path ;
    int node = n ;
    while(parent[node] != node) {
        path.push_back(node) ;
        node = parent[node]  ;
    }
    path.push_back(1) ;
    reverse(path.begin(), path.end()) ;
    return path ;
}

int main()
{



    return 0 ; 
}