#include<bits/stdc++.h>
using namespace std;

// Topological Sort Algorithm -->
// Linear ordering of Vertices such that if there is an edge b/w u and v (u --> v),
// u appeaers before v in that ordering.. 
// * --> Topological sort is only possible in Directed Acyclic Graph (DAG).

// DFS Implementation Solution ...
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1 ;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis, st) ;
        }
    }
    st.push(node) ;
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0) ;
    stack<int> st ;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st) ;
        }
    }
    vector<int> ans ;
    while(!st.empty()) {
        ans.push_back(st.top()) ;
        st.pop() ;
    }
    return ans ;
}

// ------------------------------------------------------------------------------------------   
// Kahn's Algorithm of BFS algorithm in Topological Sort ..
vector<int> topoSort(int V, vector<int> adj[]) {
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
    return topo ;
}

int main() {
    int V = 3 ;
    vector<vector<int>> adj ;
    adj[0].push_back(1) ;
    adj[0].push_back(2) ;
    
    vector<int> sortA = topoSort(V, adj) ;
    for(auto x : sortA) cout << x << " " ;
    cout << endl ;
    
	return 0 ;
}
