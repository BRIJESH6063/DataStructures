#include<bits/stdc++.h>
using namespace std ;

// Depth First Search ...
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1 ;
    ls.push_back(node) ;
    for(int i=0; )
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, adj, vis, ls) ;
    }
}

int main()
{
    vector<pair<int, int>> graph({
    {0, 8}, {1, 6}, {1, 7}, {1, 8}, {5, 8}, {6, 0}, {7, 3}, {7, 4}, {8, 7}, {2, 5}}) ;
    int V = 9 ;
    vector<int> adj[V] ;
    for(auto x : graph) {
        adj[x.first].push_back(x.second) ;
        adj[x.second].push_back(x.first) ;
    }
    // for(int i=0; i<V; i++) {
    //     sort(adj[i].begin(), adj[i].end()) ;
    // }
    int vis[V] = {0} ; vector<int> ls ;
    dfs(0, adj, vis, ls) ;
    for(auto x : ls) cout << x << " " ;
    cout << endl ;

    return 0 ;
}