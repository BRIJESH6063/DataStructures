#include<bits/stdc++.h>
using namespace std;

void SubSequence(vector<int> &v, vector<int> &a, vector<vector<int>> &ans, int i = 0 ) {
    if(i == v.size()) {
        ans.push_back(a) ; return ;
    }
    if(v.size() == 0) return ;
    a.push_back(v[i]) ;
    SubSequence(v, a, ans, i+1) ;
    a.pop_back() ;
    SubSequence(v, a, ans, i+1) ;
}

int main()
{
    vector<int> v({2,3,1, 5, 4}) ;
    vector<int> a ; vector<vector<int>> ans ;
    SubSequence(v, a, ans) ;
    for(auto x : ans) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }
	return 0 ;
}

