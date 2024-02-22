#include<bits/stdc++.h>
using namespace std ;

void SubsetSum(vector<int> &v, vector<int> &ans, int i=0, int sum = 0) {
    if(i == v.size()) {
        ans.push_back(sum) ; return ;
    }
    if(v.size() == 0) return ;
    SubsetSum(v, ans, i+1 , sum+v[i]) ;
    SubsetSum(v, ans, i+1, sum) ;
}

int main()
{
    vector<int> v({3, 1, 2}) ; vector<int> ans ;
    SubsetSum(v, ans) ;
    sort(ans.begin(), ans.end()) ;
    for(auto x : ans ) cout << x << " " ;
    cout << endl ;


    return 0 ;
}