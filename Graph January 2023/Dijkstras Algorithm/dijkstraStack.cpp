#include<bits/stdc++.h>
using namespace std ;

// Dijkstras Algorithm Stack Implementation 
// Optimising the code by dekleting the already existing path with greater weight ..
// Optimising the Time Complexity ...
// Once updated weight has already given min weight to nodes to reach them
// the revisiting those nodes will only check with greater wt than previous hence USELESS, DELETE ALREADY UPDATED ONES.
vector<int> dijkstraAlgo(int V, vector<vector<vector<int>>> &adj, int S) {
    set<pair<int, int>> st ;
    vector<int> dist(V, INT_MAX) ;
    st.insert({0, S}) ;
    dist[S] = 0 ;
    while(! st.empty()) {
        auto it = *(st.begin()) ;
        int node = it.second ;
        int dis = it.first ;
        st.erase(it) ;
        
        for(auto it : adj[node]) {
            int adjNode = it[0] ;
            int edgeWt = it[1] ;
            if(dis + edgeWt < dist[adjNode]) {
                // erase if existed 
                if(dist[adjNode] != INT_MAX) {
                    st.erase({dist[adjNode], adjNode}) ;
                }
                dist[adjNode] = dis + edgeWt ;
                st.insert({dist[adjNode], adjNode}) ;
            }
        }
    }
    return dist ;
}

int main()
{



    return 0 ; 
}