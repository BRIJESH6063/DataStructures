#include<bits/stdc++.h>
using namespace std ;

// Dijkstras Algorithm Implementation MinHeap 
vector<int> dijkstras(int V, vector<vector<int>> adj[], int s) {
    // min heap creation .. 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ; 
    vector<int> dist(V) ;
    for(int i=0; i<V; i++) dist[i] = 1e9 ;
    dist[s] = 0 ;
    pq.push({0, s}) ;
    while(! pq.empty()) {
        int dis = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;
        for(auto it : adj[node]) {
            int edgeWeight = it[1] ;
            int adjNode = it[0] ;
            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight ;
                pq.push({dist[adjNode], adjNode}) ;
            }
        }
    }
    return dist ;
}
// Time Limit exceed in coding ninjas .. 

int main()
{
    vector<vector<int>> adj[10] ;
    
    return 0 ;
}

// Dijkstra doesnt work in 
// 1. negative Weight 
// 2. negative Cycle 
// Time Complexity --> O(E log(V))