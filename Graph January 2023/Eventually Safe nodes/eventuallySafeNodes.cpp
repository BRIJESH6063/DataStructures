#include<bits/stdc++.h>
using namespace std;

// find eventual safe states ..
// A node is a terminal node if there are no outgoing edges. 
// A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node)

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
    vis[node] = 1 ;
    pathVis[node] = 1 ;
    check[node] = 0 ;
    for(auto it : adj[node]) {
        if(! vis[it]) {
            if(dfsCheck(it, adj, vis, pathVis, check) == true) 
            return true ;
        }
        // already visited node and path unavailable
        else if(pathVis[it]) return true ;
    }
    check[node] = 1 ;
    pathVis[node] = 0 ;
    return false ;   
}


vector<int> isEventualSafeNodes(int V, vector<int> adj[]) {
    int vis[V] = {0} ;
    int pathVis[V] = {0} ;
    int check[V] = {0} ;
    vector<int> safeNodes ;
    for(int i=0; i<V; i++) {
        if(! vis[i]) {
            dfsCheck(i, adj, vis, pathVis, check) ;
        }
    }
    for(int i=0; i<V; i++) {
        if(check[i] == 1) safeNodes.push_back(i) ;
    }
    return safeNodes ;
}

int main() {
    vector<int> adj[4] ;
    adj[0].push_back(1) ;
    adj[1].push_back(2) ;
    adj[2].push_back(0) ;
    adj[2].push_back(3) ;
    
    vector<int> safeNodes = isEventualSafeNodes(4, adj) ;
    for(auto it : safeNodes) cout << it << " " ;
    cout << endl ;
    
	return 0 ;
}
