// Pallindrome Partitioning Problems .... 
#include<bits/stdc++.h>
using namespace std ;

bool isPallindrome(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j]) return false ;
        i++ ; j-- ;
    }
    
    return true ;
}

void Solution(string s, vector<string> &a, vector<vector<string>> &ans, int i=0) {
    if(i == (s.size())) {
        ans.push_back(a) ; return ;
    }
    
    for(int j = i ; j< s.size(); j++) {
        if(isPallindrome(s, i, j)) {
            a.push_back(s.substr(i, j-i+1)) ;
            Solution(s, a, ans, j+1) ;
            a.pop_back() ;
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans ; vector<string> a ;
    Solution(s, a, ans) ;
    
    return ans ; 
}

int main()
{
    string s = "aabb" ;
    vector<vector<string>> ans = partition(s) ;
    
    for(auto x : ans ) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }
    
    
    
    return 0;
}