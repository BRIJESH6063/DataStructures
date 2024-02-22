#include<bits/stdc++.h>
using namespace std ;

// BFS implementation ...
vector<int> bfsTraverse(int V, vector<int> adj[]) {
    int vis[V] = {0} ;
    queue<int> q ;
    vector<int> bfs ;
    for(int i=0; i<V; i++) {
        if(vis[i] == 0) {
            q.push(i) ; vis[i] = 1 ;
            while(!q.empty()) {
                int node = q.front() ;
                bfs.push_back(node) ;
                q.pop() ;
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1 ; q.push(it) ;
                    }
                }
            }
        }
    }  
    return bfs ;
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
    for(int i=0; i<9; i++) {
        sort(adj[i].begin(), adj[i].end()) ;
    }
    vector<int> bfs = bfsTraverse(V, adj) ;
    for(auto x : bfs) cout << x << " " ;
    cout << endl ;


    
    return 0 ;
}