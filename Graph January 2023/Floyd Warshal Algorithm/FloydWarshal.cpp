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

// Detecting The NEGATIVE CYCLE 
// For any node cost to reach itself must be zero, if cost is negative
// then there exist a negative cycle. 
// Implementation .. 
void ShortestDistance(vector<vector<int>> &matrix) {
    int n = matrix.size() ;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 1e9 ;
            if(i == j) matrix[i][j] = 0 ;
        }
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = min(matrix[i][j],
                matrix[i][k]+matrix[k][j]) ;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 1e9) matrix[i][j] = -1 ;
        }
    }
   // Cycle detection code by Floyd Warshal Algorithm 
   // for(int i=0; i<n; i++) {
   //    if(matrix[i][i] < 0) return true ;
   // }
   // return false ;
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


