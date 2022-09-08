#include<bits/stdc++.h>
using namespace std ;

void TakeInput(stack<int> &stk)
{
    int data ; cin >> data ;
    while(data != -1){
        stk.push(data) ;
        cin >> data ;
    }
}
void PrintStack(stack<int> stk){
    while(!stk.empty()){
        cout << stk.top() << " " ;
        stk.pop() ;
    }
    cout << endl ;
}

int main()
{
    stack<int> stk ;
    TakeInput(stk) ;
    // for(auto x : stk) cout << x << " " ;
    // cout << endl ;
    cout << stk.top()  << endl ;
    PrintStack(stk) ;
    stk.pop()  ;
    cout << stk.size() << endl ;
    PrintStack(stk) ;
    return 0 ;
}