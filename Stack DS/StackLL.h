#include<bits/stdc++.h>
#include"stackLL.cpp"
using namespace std ;

template<typename T> 
void TakeInputSLL(StackLL<T>* &stk){
    int data ; cin >> data ;
    while(data != -1){
        stk->push(data) ;
        cin >> data ;
    }
}

template<typename T> 
void printStackLL(StackLL<T>* stk){
    Node<T>* temp = stk->top() ;
    while(temp){
        cout << temp->data << " " ;
    } 
    cout << endl ;
}