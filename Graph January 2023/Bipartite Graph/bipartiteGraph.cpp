#include<bits/stdc++.h>
using namespace std;

// Bipartite check BFS Implementation ... 
// bool check(int start, int V, vector<int> adj[], int color[]) {
//     queue<int> q ;
//     q.push(start) ;
//     color[start] = 0 ;
//     while(!q.empty()) {
//         int node = q.front() ;
//         q.pop() ;
//         for(auto it : adj[node]) {
//             if(color[it] == -1) {
//                 color[it] = !color[node] ;
//                 q.push(it) ;
//             }
//             // if already colored wrong .. 
//             else if(color[it] == color[node]) 
//             return false ;
//         }
//     }
//     return true ;
// }

// bool isBipartite(int V, vector<int> adj[]) {
//     int color[V] = {-1} ;
//     for(int i=0; i<V; i++) {
//         if(color[i] == -1) {
//             if(check(i, V, adj, color) == false)
//             return false ;
//         }
//     }
//     return true ;
// }

// ---------------------------------------------------------------------------------
// check DFS Implementation ... 
bool checkDFS(int node, int col, vector<int> &color, vector<int> adj[]) {
    color[node] = col ;
    for(auto it : adj[node] ) {
        if(color[it] == -1) {
            if(checkDFS(it, !col, color, adj) == false) 
            return false ;
        }
        else if(color[it] == color[node])
        return false ;
    }
    return true ;
}

// Bipartite call function 
bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1) ;
    for(int i=0; i<V; i++) {
        if(color[i] == -1) {
            if(checkDFS(i, 0, color, adj) == false)
            return false ;
        }
    }
    return true ;
}
// --------------------------------------------------------------


int main() {
    vector<int> adj[3] ;
    adj[0] = {1} ;
    adj[1] = {0, 2} ;
    adj[2] = {1} ;
    // adj[3] = {0,2} ;
    if(isBipartite(3, adj)) cout << "Graph is Bipartite . " << endl ;
    else cout << "Graph is not Bipartite . " << endl ;
    
    
	return 0 ;
}
