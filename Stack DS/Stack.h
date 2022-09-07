#include<bits/stdc++.h>
#include"stack.cpp"
using namespace std ;

void TakeInput(Stack* &stk){
    int data ; cin >> data ;
    while(data != -1){
        stk->push(data) ;
        cin >> data ;
    }
}

void printStack(Stack* stk){
    int topE = stk->getTop() ; int* arr1 = stk->getArr() ;
    for(int i=0; i<=topE; i++) cout << arr1[i] << "   " ;
    cout << endl ;
}