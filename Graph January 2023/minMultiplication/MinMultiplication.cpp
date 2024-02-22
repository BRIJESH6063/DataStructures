#include<bits/stdc++.h>
#include<time.h>
using namespace std;

// Minimum multiplication to reach end  .. 
// Check a number product with every other number of array leading to target
int minMultiplication(vector<int> &arr, int start, int end) {
    queue<pair<int, int>> q ;
    q.push({start, 0}) ;
    vector<int> dist(100000, 1e9) ;
    int mod = 100000 ;
    while(! q.empty()) {
      int node = q.front().first ;
      int steps = q.front().second ;
      q.pop() ;
      for(auto it : arr) {
         int num = (it*node)%mod ;
         if(steps+1 < dist[num]) {
            dist[num] = 1+steps ;
            if(num == end) return steps+ 1 ;
            q.push({num, steps+1}) ;
         }
      }
    }
    return -1 ;
}

int main() {
   // ios_base::sync_with_stdio(false); cin.tie(NULL) ;

   // #ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin) ;
   // freopen("output.txt", "w", stdout) ;
   // #endif 

   cout << "Hello World!.." << endl ;

   return 0;
}


