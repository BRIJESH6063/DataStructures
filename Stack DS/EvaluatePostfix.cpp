// Reverse Polish Notation (Postfix evaluation.)

#include<bits/stdc++.h>
using namespace std ;

int operate(int a, int b, string i){
    if(i=="+") return a+b ;
    else if(i=="-") return a-b ;
    else if(i=="*") return a*b ;
    else if(i=="/") return a/b ;
}

bool isOperator(string i){
    return (i == "+") || (i == "-") || 
           (i == "*") || (i == "/") ;
}

int evaluatePostfix(vector<string> s){
    stack<int> stk ;
    for(int i=0; i<s.size(); i++){
        if(!isOperator(s[i])) stk.push(stoi(s[i])) ;
        else {
            int a = stk.top() ; stk.pop() ; int b = stk.top() ; stk.pop() ;
            int ans = operate(a, b, s[i]) ;
            stk.push(ans) ;
        } 
    }
    if(stk.size() == 1) return stk.top() ;
    else return INT_MAX ;
}

void takeInput(vector<string> &s){
    string data ; cin >> data ;
    while(data != "."){
        s.push_back(data) ;
        cin >> data ;
    }
}

int main()
{
    vector<string> s ; takeInput(s) ;
    if(evaluatePostfix(s) == INT_MAX) cout << "Wrong Input!." << endl ;
    else cout << "Resultant is : "<< evaluatePostfix(s) << << endl ;

    return 0 ;
}