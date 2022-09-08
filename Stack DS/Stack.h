#include<bits/stdc++.h>
#include"stack.cpp"
using namespace std ;

void TakeInput(Stack<char>* &stk){
    int data ; cin >> data ;
    while(data != -1){
        stk->push(data) ;
        cin >> data ;
    }
}

void printStack(Stack<char>* stk){
    int topE = stk->getTop() ; char* arr1 = stk->getArr() ;
    for(int i=0; i<=topE; i++) cout << arr1[i] << "  " ;
    cout << endl ;
}