// Balanced Bracket Problem Method2.

#include<bits/stdc++.h>
using namespace std ;


bool isBalanced(string str)
{
    map<char, int> m ;
    m['('] = -1 ; m['{'] = -2 ; m['['] = -3 ; m[')'] = 1 ; m['}'] = 2 ; m[']'] = 3 ; 
    stack<int> s; 
    for(int i=0; i<str.length(); i++){
        if(m[str[i]] < 0) s.push(m[str[i]]) ;
        else {
            if(s.empty()) return false ;
            else if(m[str[i]]+s.top() != 0) return false ;
            else s.pop() ;
        }
    }
    return (s.empty()) ;
}

int main()
{
    string s ; cin >> s ;
    cout << isBalanced(s) << endl ;
    
    
    return 0 ;
}