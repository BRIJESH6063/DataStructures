#include<bits/stdc++.h>
using namespace std ;

bool BalancedParenthesis(string s)
{
    map<char, int> m ;
    m['('] = -1 ; m['{'] = -2 ; m['['] = -3 ; 
    m[')'] =  1 ; m['}'] =  2 ; m[']'] = -3 ; 
    stack<int> stk ;  bool result = true ;
    for(int i=0; i<s.size(); i++){
        if(m[s[i]] < 0) stk.push(m[s[i]]) ;
        else {
            if(stk.empty()) return false ;
            else if(m[s[i]]+stk.top() == 0) stk.pop() ;
            else return false ;
        }
    }
    if(stk.empty()) return true ;
    else return false ;
}
int main()
{
    string s ; cin >> s ;
    if(BalancedParenthesis(s)) cout << "Balanced Paranthesis spotted." << endl ;
    else cout << "Not a Balanced Paranthesis." ; 


    return 0 ;
}