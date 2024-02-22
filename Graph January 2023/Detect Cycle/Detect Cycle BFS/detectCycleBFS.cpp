#include <bits/stdc++.h>
using namespace std;

// Detect a cycle in undirected graph using BFS
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1 ;
    queue<pair<int, int>> q ;
    q.push({src, -1}) ;
    while(!q.empty()) {
        int node = q.front().first ;
        int parent = q.front().second ;
        q.pop() ;
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                vis[adjNode] = 1 ;
                q.push({adjNode, node}) ;
            }
            else if(parent != adjNode) return true ;
        }
    }
    return false ;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V+1] = {0} ;
    for(int i=1; i<=V; i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) 
            return true ;
        }
    }
    return false ;
}


int main() {
    int V = 7 ;
    vector<int> adj[V+1] ;
    adj[1].push_back(2) ; adj[1].push_back(3) ;
    adj[2].push_back(1) ; adj[2].push_back(5) ;
    adj[3].push_back(1) ; adj[3].push_back(4) ; adj[3].push_back(6) ; 
    adj[4].push_back(3) ; 
    adj[5].push_back(2) ; // adj[5].push_back(7) ;
    adj[6].push_back(3) ; adj[6].push_back(7) ;
    // adj[7].push_back(5) ; 
    adj[7].push_back(6) ;
    if(isCycle(V, adj)) cout << "Cycle Detected!.." << endl ;
    else cout << "Cycle Not Detected!.." << endl ;
	
	return 0 ;
}
