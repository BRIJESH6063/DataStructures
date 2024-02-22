// longest subarray zero sum problem .. 

#include <bits/stdc++.h>
using namespace std;
    
int main() {
	int n ; cin >> n ; int a[n] ; vector<int> v ;
	for(int i=0; i<n; i++) cin >> a[i] ; int res = INT_MIN ;
	int preSum = 0 ;
	unordered_map<int, int> m ;
	for(int i=0; i<n; i++)  {
	    preSum += a[i] ;
	    if(preSum == 0) res ++ ;
	    if(m.find(preSum) != m.end()) res = max(res, i-m[preSum]) ;
	    else m[preSum] = i ;
	    
	    if(res == INT_MIN) v.push_back(0) ;
	    else v.push_back(res) ;
	}
	for(auto x : v) cout << x << " " ;
	cout << endl ;
	cout << res << endl ;
	
	return 0;
}
