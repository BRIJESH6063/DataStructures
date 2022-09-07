#include<bits/stdc++.h>
#include"Stack.h"
using namespace std; 

int main()
{
    Stack* stk = new Stack() ;
    cout << stk->getCapacity() << endl ;
    TakeInput(stk)  ;
    printStack(stk) ;
    cout << stk->getCapacity() << endl ;

    return 0 ;
}