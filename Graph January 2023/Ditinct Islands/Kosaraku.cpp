#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// G54. Most stones removed with same Row and Column 
// Strongly Connected Algorithm, [KosaRaju's Algorithm]
// Strongly connnected Components --> Subgraphs when each element can redirect to itself
// code Implementation ...
void DFS(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
   vis[node] = 1 ;
   for(auto it : adj[node]) {
      if(! vis[it]) {
         DFS(it, vis, adj, st) ;
      }
   }
   st.push(node) ;
}

void dfs3(int node, vector<int> &vis, vector<int> adj[]) {
   vis[node] = 1 ;
   for(auto it : adj[node]) {
      if(!vis[it]) dfs3(it, vis, adj) ;
   }
}


int KosaRaju(int V, vector<int> adj[]) {
   vector<int> vis(V, 0) ;
   stack<int> st ;
   for(int i=0; i<V; i++) {
      if(!vis[i]) {
         DFS(i, vis, adj, st) ;
      }
   }
   vector<int> adjT[V] ;
   for(int i=0; i<V; i++) {
      vis[i] = 0 ;
      for(auto it : adj[i]) {
         adjT[it].push_back(i) ;
      }
   }
   int ssc = 0 ; // strongly connected components.. 
   while(! st.empty()) {
      int node = st.top() ;
      st.pop() ;
      if(!vis[node]) {
         ssc++ ;
         dfs3(node, vis, adjT) ;
      }
   }
   return ssc ;
}

void sublimeInit() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL) ;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin) ;
   freopen("output.txt", "w", stdout) ;
   #endif 
}

int main() {
   // sublimeInit() ;
   cout << "Hello World!.." << endl ;




   return 0;
}

// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
// failed --> Runtime Error .