#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Floyd Warshal Algorithm -> Multiple Source Node 
// Other Shortest path Algorithm single source node 
// for(via = 0; via<n; via++) {
//    for(i=0; i<n; i++) {
//       for(j=0; j<n; j++) {
//          cost[i][j] = min(cost[i][j], 
//             cost[i][via] + cost[via][j]) ;
//       }
//    }
// }

// Find the city with smallest number of cities that are reachable
// through somne path at the Threshold Distance (at max Dist).
// In case of multiple answer return city with maximum number. 
// Code Implementation ..
int findCity(int n, vector<vector<int>> &edges, int distThreshold) {
   vector<vector<int>> dist(n, vector<int>(n, INT_MAX)) ;
   for(auto it : edges) {
      dist[it[0]][it[1]] = it[2] ;
      dist[it[1]][it[0]] = it[2] ;
   }
   for(int i=0; i<n; i++) dist[i][i] = 0 ;
   for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) {
         for(int j=0; j<n; j++) {
            if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
               dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]) ;
            }
         }
      }
   }
   int cntCity = n ;
   int cityNo = -1 ;
   for(int city=0; city<n; city++) {
      int cnt=0; 
      for(int adjCity=0; adjCity<n; adjCity++) {
         if(dist[city][adjCity] <= distThreshold) cnt++ ;
      }
      if(cnt <= cntCity) {
         cntCity = cnt ;
         cityNo = city ;
      }
   }
   return cityNo ;
}


void sublimeInit() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL) ;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin) ;
   freopen("output.txt", "w", stdout) ;
   #endif 
}

int main() {
//    sublimeInit() ;
   cout << "Hello World!.." << endl ;

   return 0;
}


