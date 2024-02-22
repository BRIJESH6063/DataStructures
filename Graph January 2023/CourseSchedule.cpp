#include<bits/stdc++.h>
using namespace std;

// Course Schedule I and II
// Prequisite Task ...
// Given number of task N and and a list of prequisite pairs P 
// find if it is possible to finish all the tasks?

// Algorithm --> Topological Sort 
// possible --> YES(if Directed Acyclic), NO(if not)
// Directed Acyclic means --> topo.size() == V 

// Kahn's Algorithm of BFS algorithm in Topological Sort ..
vector<int> TaskOrder(int V, vector<int> adj[]) {
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
    // Directed Acyclic means --> topo.size() == V 
    if(topo.size() == V) return topo ;
    return {} ;
}


int main() {
    
    
	return 0 ;
}
