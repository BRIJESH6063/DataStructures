#include <bits/stdc++.h>
using namespace std;

// DFS Implementation ...
void dfs(int node, vector<int> adj[], int vis[]) {
    vis[node] = 1 ;
    for(auto x : adj[node]) {
        if(!vis[x]) dfs(x, adj, vis) ;
    }
}

// Count Provinces...
int numProvinces(vector<vector<int>> matrix, int V) {
    vector<int> adj[V] ;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(matrix[i][j]) {
                adj[i].push_back(j) ;
                adj[j].push_back(i) ;
            }
        }
    }
    int count = 0 ;
    int vis[V] = {0} ;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            count ++ ;
            dfs(i, adj, vis) ;
        }
    }
    
    return count ;
}

int main() {
    vector<vector<int>> matrix({ {1, 0, 1},
                                 {0, 1, 0},
                                 {1, 0, 1} }) ;
    int V = matrix.size() ;
    cout << numProvinces(matrix, V) << endl ;
	
	return 0 ;
}
