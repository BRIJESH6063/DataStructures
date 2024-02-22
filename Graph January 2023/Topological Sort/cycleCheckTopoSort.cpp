#include<bits/stdc++.h>
using namespace std;

// cycle detection in directed graph using Topological Sort BFS implementation 
// Kahn's Algorithm of BFS algorithm in Topological Sort ..
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0) ;
    for(int i=0; i<V; i++) {
        for(auto x : adj[i]) 
        indegree[x] ++ ;
    }
    queue<int> q ;
    for(int i=0; i<V; i++) {
        if(indegree[i] == 0) q.push(i) ;
    }
    vector<int> topo ;
    while(! q.empty()) {
        int node = q.front() ;
        q.pop() ;
        topo.push_back(node) ;
        for(auto it : adj[node]) {
            indegree[it] -- ;
            if(indegree[it] == 0)
            q.push(it) ;
        }
    }
    // if toposort size == total nodes --> 
    return topo.size() != V ;
}

int main() {
    
    
	return 0 ;
}
