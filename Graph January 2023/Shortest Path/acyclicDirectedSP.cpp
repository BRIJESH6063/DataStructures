#include<bits/stdc++.h>
using namespace std;

// Shortest path in directed Acyclic Graph 
// Shortest path from src(0)

// Generate the topological sort (DFS method) of the graph and 
// update the distance array as per toposorted array serial elements .. 
void toposort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {
    vis[node] = 1 ;
    for(auto it : adj[node]) {
        int v = it.first ;
        if(!vis[v]) {
            toposort(v, adj, vis, st) ;
        }
    }
    st.push(node) ;
}
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n] ;
    for(int i=0; i<n; i++) {
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        int w = edges[i][1] ;
        adj[u].push_back({v, w}) ;
    }
    
    int vis[n] = {0} ;
    stack<int> st ;
    for(int i=0; i<n; i++) {
        if(! vis[i]) 
        toposort(i, adj, vis, st) ;
    }
    
    vector<int> dist(n) ;
    for(int i=0; i<n; i++) dist[i] = 1e9 ;
    for(int i=0; i<n; i++) cout << dist[i] << "  " ;
    cout << endl ;
    dist[0] = 0 ;
    while(!st.empty()) {
        int node = st.top() ;
        
        st.pop() ;
        for(auto it : adj[node]) {
            int v = it.first ;
            int wt = it.second ;
            if(dist[node] + wt < dist[v]) {
                dist[v] = dist[node] + wt ;
            }
        }
    }
    for(int i=0; i<n; i++) cout << dist[i] << "  ";
    cout << endl ;
    for(int i=0; i<n; i++) {
        if(dist[i] == 1e9) dist[i] = -1 ;
    }
    return dist ;
}

int main() {
    
	return 0 ;
}
