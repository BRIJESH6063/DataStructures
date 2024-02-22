// Balanced Bracket Problem 

#include<bits/stdc++.h>
using namespace std ;

bool matching(char a, char b)
{
    return ((a == '(' and b == ')') ||
            (a == '{' and b == '}') ||
            (a == '[' and b == ']')  ) ;
}

bool isBalanced(string str)
{
    stack<int> s; 
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(' or str[i] == '{' or str[i] == '[')
        s.push(str[i]) ;
        else {
            if(s.empty()) return false ;
            else if(!matching(s.top(), str[i])) return false ;
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