#include<bits/stdc++.h>
using namespace std ;

// DFS Implementation for cycle detection in directed Graph  ....
// Take two array --->
// 1 . visited array ---> denotes array visited at least once 
// 2 . visited path ----> denotes if path is available to visite

bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1 ;
    pathVis[node] = 1 ;
    // Traversal of Adjacent Nodes ..
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfsCheck(it, adj, vis, pathVis) == true) 
            return true ;
        }
        else if(pathVis[it]) return true ;
    }
    
    pathVis[node] = 0 ;
    return false ;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0) ;
    vector<int> pathVis(V, 0) ;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(dfsCheck(i, adj, vis, pathVis) == true) 
            return true ;
        }
    }
    return false ;
}

// Second approach .. 
// single array can also solve the problem 0 -> unvisited 1 -> visited path available  2 -> visited path unavailable 

int main() {
    vector<int> adj[5] ;
    // adj[1].push_back(2) ;
    // adj[4].push_back(1) ;
    // adj[2].push_back(4) ;
    // adj[3].push_back(4) ;
    // adj[5].push_back(2) ;
    // adj[1].push_back(3) ; wrong
    // code is correct 
    if(isCyclic(5, adj)) cout << "Cycle Detected!.." << endl ;
    else cout << "Cycle Not Detected!.. " << endl ;
    
    
	return 0 ;
}
