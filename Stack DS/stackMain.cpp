#include<bits/stdc++.h>
#include"Stack.h"
using namespace std; 

int main()
{
    Stack<char>* stk = new Stack<char>() ;
    cout << stk->getCapacity() << endl ;
    TakeInput(stk)  ;
    printStack(stk) ;
    cout << stk->getCapacity() << endl ;

    return 0 ;
}