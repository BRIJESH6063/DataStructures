#include<bits/stdc++.h>
using namespace std ;

bool isMatch(char a, char b){
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']') ;
}

bool BalancedParenthesis(string s)
{ 
    stack<int> stk ;  
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]) ;
        else {
            // cout << "removed : " << stk.top() << endl ;
            if(stk.empty()) return false ;
            else if(isMatch(stk.top(), s[i])) stk.pop() ;
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