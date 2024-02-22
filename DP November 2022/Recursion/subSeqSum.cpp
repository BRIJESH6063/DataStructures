#include<bits/stdc++.h>
using namespace std;

// void SubSeqSum(vector<int> &v, vector<int> &a, vector<vector<int>> &ans, int sum, int s=0, int i = 0) {
//     if(i == v.size()) {
//         if(s == sum) ans.push_back(a) ;
//         return ;
//     }
//     a.push_back(v[i]) ; s += v[i] ;
//     SubSeqSum(v, a, ans, sum, s, i+1) ;
//     a.pop_back() ; s -= v[i] ;
//     SubSeqSum(v, a, ans, sum, s, i+1) ;

// }

// use set to remove duplicacy.. 
void SubSeqSum(vector<int> &v, vector<int> &a, set<vector<int>> &ans, int sum, int s=0, int i = 0) {
    if(i == v.size()) {
        if(s == sum) ans.insert(a) ;
        return ;
    }
    a.push_back(v[i]) ; s += v[i] ;
    SubSeqSum(v, a, ans, sum, s, i+1) ;
    a.pop_back() ; s -= v[i] ;
    SubSeqSum(v, a, ans, sum, s, i+1) ;
    
}

int main()
{
    vector<int> v({2,3,1,1,1}) ; int sum = 3 ;
    vector<int> a ; set<vector<int>> ans ;
    SubSeqSum(v, a, ans, sum) ;
    for(auto x : ans) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }


    cout << "count : " << ans.size() << endl ;
	return 0 ;
}

