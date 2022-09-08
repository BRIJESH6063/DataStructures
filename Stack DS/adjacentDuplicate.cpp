// Remove all adjacent duplicacy

#include<bits/stdc++.h>
using namespace std ;

string removeAdjDup(string s){
    stack<char> stk ;
    string ans = "" ;
    for(int i=0; i<s.size(); i++){
        if(stk.empty() || s[i] != stk.top()) stk.push(s[i]) ;
        else stk.pop() ;
    }

    while(stk.empty() == false) {
        ans.push_back(stk.top()) ; stk.pop() ;
    }
    reverse(ans.begin(), ans.end()) ;
    return ans ;
}

int main()
{
    string s ; cin >> s ;
    string ans = removeAdjDup(s) ;
    cout << ans << endl ;

    return 0 ;
}