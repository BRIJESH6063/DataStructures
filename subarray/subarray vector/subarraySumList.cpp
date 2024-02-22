#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> s ; vector<int> v ; vector<vector<int>> ans ;
    int preSum = 0 ; int res = 0 ;  int n = candidates.size() ;
    
    for(int i=0; i<n; i++) {
        preSum += candidates[i] ; s.push_back(preSum) ;
        if(preSum == target) {
            vector<int> temp(candidates.begin(), candidates.begin()) ;
            ans.push_back(temp) ; 
        }
        else if(find(s.begin(), s.end(), preSum-target) != s.end()) {
            auto x = find(s.begin(), s.end(), preSum-target) ; 
            vector<int> temp ; 
            for(auto y=x+1; y!=s.end(); y++) {
                temp.push_back((*y)-(*(y-1))) ;
            }
            ans.push_back(temp) ; continue ;
        }
    }
    
    return ans ;
}

int main() {
    vector<int> candidates({2,3,4,6,7,1,1,5,4}) ; int target = 7 ;
    
    vector<vector<int>> ans = combinationSum(candidates, target) ;
    for(auto x : ans ) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }
    
	return 0;
}
